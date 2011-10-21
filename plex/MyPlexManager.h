#pragma once

/*
 *  Copyright 2011 Plex Development Team. All rights reserved.
 *
 */

#include <string>
#include <tinyXML/tinyxml.h>

#include "GUISettings.h"
#include "CocoaUtils.h"
#include "CocoaUtilsPlus.h"
#include "Log.h"
#include "FileCurl.h"

using namespace std;
using namespace XFILE;

#ifdef _DEBUG
const string cMyPlexURL = "mydev.plexapp.com";
#else
const string cMyPlexURL = "my.plexapp.com";
#endif

class MyPlexManager
{
 public:
  
  MyPlexManager()
  {
  }
  
  /// Sign in.
  bool signIn()
  {
    CFileCurl http;
    http.SetUserAndPassword(g_guiSettings.GetString("myplex.email"), g_guiSettings.GetString("myplex.password"));
    setRequestHeaders(http);
    
    // Issue the sign-in request.
    CStdString res;
    string request = getMyPlexBaseUrl(false) + "/users/sign_in.xml";
    bool success = http.Post(request, "", res);
    
    if (success && res.empty() == false)
    {
      // Parse returned xml.
      TiXmlDocument doc;
      if (doc.Parse(res.c_str()))
      {
        TiXmlElement* root = doc.RootElement();
        if (root && root->ValueStr() == "user")
        {
          TiXmlNode* token = root->FirstChild("authentication-token");
          if (token)
          {
            const char* strToken = token->FirstChild()->Value();
            
            // Save the token.
            dprintf("Setting myPlex token to %s", strToken);
            g_guiSettings.SetString("myplex.token", strToken);
            
            return true;
          }
        }
      }
    }
    
    // Reset the token.
    g_guiSettings.SetString("myplex.token", "");
    return false;
  }
  
  /// Sign out.
  void signOut()
  {
    g_guiSettings.SetString("myplex.token", "");
  }
  
  /// Get the contents of a playlist.
  void getPlaylist(const string& playlist)
  {
    
  }
  
  /// Get all sections.
  void getSections()
  {
    
  }
  
 protected:
  
  void setRequestHeaders(CFileCurl& http)
  {
    // Initialize headers.
    http.SetRequestHeader("Content-Type", "application/xml");
    http.SetRequestHeader("X-Plex-Client-Identifier", g_guiSettings.GetString("system.uuid"));
    http.SetRequestHeader("X-Plex-Product", "Plex Media Center");
    http.SetRequestHeader("X-Plex-Version", Cocoa_GetAppVersion());
    http.SetRequestHeader("X-Plex-Provides", "player");
    http.SetRequestHeader("X-Plex-Platform", Cocoa_GetMachinePlatform());
    http.SetRequestHeader("X-Plex-Platform-Version", Cocoa_GetMachinePlatformVersion());
  }
  
  string getMyPlexBaseUrl(bool secure=true)
  {
    string ret;
    
    // Allow the environment variable to override the default, useful for debugging.
    if (getenv("MYPLEX_URL"))
      ret = getenv("MYPLEX_URL");
    else
      ret = (secure ? "https://" : "http://") + cMyPlexURL;
    
    return ret;
  }
};
