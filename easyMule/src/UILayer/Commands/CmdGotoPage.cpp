/*
 * $Id: CmdGotoPage.cpp 19246 2010-04-29 08:23:47Z dgkang $
 * 
 * this file is part of easyMule
 * Copyright (C)2002-2008 VeryCD Dev Team ( strEmail.Format("%s@%s", "emuledev", "verycd.com") / http: * www.easymule.org )
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
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
#include "StdAfx.h"
#include ".\cmdgotopage.h"
#include "eMule.h"
#include "eMuleDlg.h"

CCmdGotoPage::CCmdGotoPage(void)
{
}

CCmdGotoPage::~CCmdGotoPage(void)
{
}

void CCmdGotoPage::GotoDownloading(void)
{
	theApp.emuledlg->m_mainTabWnd.SetActiveTabById(CMainTabWnd::TI_DOWNLOAD);
	theApp.emuledlg->m_mainTabWnd.m_dlgDownload.SetDownloadlistActiveTab(CDlgMaintabDownload::TI_DOWNLOADING);
}

// �����ҳ��
void CCmdGotoPage::GotoSubscribe(void)
{
	ASSERT(theApp.emuledlg != NULL);
	theApp.emuledlg->m_mainTabWnd.SetActiveTabById(CMainTabWnd::TI_DOWNLOAD);
	theApp.emuledlg->m_mainTabWnd.m_dlgDownload.SetDownloadlistActiveTab(CDlgMaintabDownload::TI_RSSWND);
}
