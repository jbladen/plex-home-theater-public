/*
* XBoxMediaCenter
* Copyright (c) 2003 Frodo/jcmarshall
* Portions Copyright (c) by the authors of ffmpeg / xvid /mplayer
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/
#include "../../stdafx.h"
#include "RenderManager.h"

#include "PixelShaderRenderer.h"
#include "ComboRenderer.h"
#include "RGBRenderer.h"


CXBoxRenderManager g_renderManager;

CXBoxRenderManager::CXBoxRenderManager()
{
  CExclusiveLock lock(m_sharedSection);
  m_pRenderer = NULL;
  m_bPauseDrawing = false;
}

CXBoxRenderManager::~CXBoxRenderManager()
{
  CExclusiveLock lock(m_sharedSection);
  if (m_pRenderer)
    delete m_pRenderer;
  m_pRenderer = NULL;
}

unsigned int CXBoxRenderManager::Configure(unsigned int width, unsigned int height, unsigned int d_width, unsigned int d_height, float fps)
{
  CExclusiveLock lock(m_sharedSection);
  m_iSourceWidth = width;
  m_iSourceHeight = height;
  unsigned int result = 0;
  if (m_pRenderer)
  {
    result = m_pRenderer->Configure(width, height, d_width, d_height, fps);
    Update(false);
    m_bIsStarted = true;
  }
  return result;
}

void CXBoxRenderManager::Update(bool bPauseDrawing)
{
  CExclusiveLock lock(m_sharedSection);
  m_bPauseDrawing = bPauseDrawing;
  if (m_pRenderer)
  {
    m_pRenderer->Update(bPauseDrawing);
  }
}

unsigned int CXBoxRenderManager::PreInit()
{
  CExclusiveLock lock(m_sharedSection);
  m_bIsStarted = false;
  m_bPauseDrawing = false;
  if (!m_pRenderer)
  { // no renderer
    if (g_guiSettings.GetInt("VideoPlayer.RenderMethod") == RENDER_OVERLAYS)
    {
      CLog::Log(LOGDEBUG, __FUNCTION__" - Selected Overlay-Renderer");
      m_pRenderer = new CComboRenderer(g_graphicsContext.Get3DDevice());
    }
    else if (g_guiSettings.GetInt("VideoPlayer.RenderMethod") == RENDER_HQ_RGB_SHADER)
    {
      CLog::Log(LOGDEBUG, __FUNCTION__" - Selected RGB-Renderer");
      m_pRenderer = new CRGBRenderer(g_graphicsContext.Get3DDevice());
    }
    else // if (g_guiSettings.GetInt("VideoPlayer.RenderMethod") == RENDER_LQ_RGB_SHADER)
    {
      CLog::Log(LOGDEBUG, __FUNCTION__" - Selected LQShader-Renderer");
      m_pRenderer = new CPixelShaderRenderer(g_graphicsContext.Get3DDevice());
    }
  }

  return m_pRenderer->PreInit();
}

void CXBoxRenderManager::UnInit()
{
  CExclusiveLock lock(m_sharedSection);
  if (m_pRenderer)
  {
    m_pRenderer->UnInit();
    delete m_pRenderer;
    m_pRenderer = NULL;
  }
}

void CXBoxRenderManager::SetupScreenshot()
{
  CSharedLock lock(m_sharedSection);
  if (m_pRenderer)
    m_pRenderer->SetupScreenshot();
}

void CXBoxRenderManager::CreateThumbnail(LPDIRECT3DSURFACE8 surface, unsigned int width, unsigned int height)
{
  CSharedLock lock(m_sharedSection);
  if (m_pRenderer)
    m_pRenderer->CreateThumbnail(surface, width, height);
}