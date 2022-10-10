# Microsoft Developer Studio Project File - Name="WinDeKikaigoV2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** 編集しないでください **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=WinDeKikaigoV2 - Win32 Debug
!MESSAGE これは有効なﾒｲｸﾌｧｲﾙではありません。 このﾌﾟﾛｼﾞｪｸﾄをﾋﾞﾙﾄﾞするためには NMAKE を使用してください。
!MESSAGE [ﾒｲｸﾌｧｲﾙのｴｸｽﾎﾟｰﾄ] ｺﾏﾝﾄﾞを使用して実行してください
!MESSAGE 
!MESSAGE NMAKE /f "WinDeKikaigoV2.mak".
!MESSAGE 
!MESSAGE NMAKE の実行時に構成を指定できます
!MESSAGE ｺﾏﾝﾄﾞ ﾗｲﾝ上でﾏｸﾛの設定を定義します。例:
!MESSAGE 
!MESSAGE NMAKE /f "WinDeKikaigoV2.mak" CFG="WinDeKikaigoV2 - Win32 Debug"
!MESSAGE 
!MESSAGE 選択可能なﾋﾞﾙﾄﾞ ﾓｰﾄﾞ:
!MESSAGE 
!MESSAGE "WinDeKikaigoV2 - Win32 Release" ("Win32 (x86) Application" 用)
!MESSAGE "WinDeKikaigoV2 - Win32 Debug" ("Win32 (x86) Application" 用)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "WinDeKikaigoV2 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 msimg32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "WinDeKikaigoV2 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_UNICODE" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x411 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 msimg32.lib /nologo /entry:"wWinMainCRTStartup" /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "WinDeKikaigoV2 - Win32 Release"
# Name "WinDeKikaigoV2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AsmInputBar.cpp
# End Source File
# Begin Source File

SOURCE=.\AsmInputBarDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AsmViewV2.cpp
# End Source File
# Begin Source File

SOURCE=.\BinViewV2.cpp
# End Source File
# Begin Source File

SOURCE=.\Emu6502.cpp
# End Source File
# Begin Source File

SOURCE=.\Emu6502OutputV2.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\VmWindow.cpp
# End Source File
# Begin Source File

SOURCE=.\WinDeKikaigoV2.cpp
# End Source File
# Begin Source File

SOURCE=.\WinDeKikaigoV2.rc
# End Source File
# Begin Source File

SOURCE=.\WinDeKikaigoV2Doc.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AsmInputBar.h
# End Source File
# Begin Source File

SOURCE=.\AsmInputBarDlg.h
# End Source File
# Begin Source File

SOURCE=.\AsmViewV2.h
# End Source File
# Begin Source File

SOURCE=.\BinViewV2.h
# End Source File
# Begin Source File

SOURCE=.\Emu6502.h
# End Source File
# Begin Source File

SOURCE=.\Emu6502OutputV2.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\VmWindow.h
# End Source File
# Begin Source File

SOURCE=.\WinDeKikaigoV2.h
# End Source File
# Begin Source File

SOURCE=.\WinDeKikaigoV2Doc.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\adc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\and.bmp
# End Source File
# Begin Source File

SOURCE=.\res\asl.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bcc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bcs.bmp
# End Source File
# Begin Source File

SOURCE=.\res\beq.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bit.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bmi.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bne.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bpl.bmp
# End Source File
# Begin Source File

SOURCE=.\res\brk.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bvc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bvs.bmp
# End Source File
# Begin Source File

SOURCE=.\res\clc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cld.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cli.bmp
# End Source File
# Begin Source File

SOURCE=.\res\clv.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cmp.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cpx.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cpy.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dec.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dex.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dey.bmp
# End Source File
# Begin Source File

SOURCE=.\res\eor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\inc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\inx.bmp
# End Source File
# Begin Source File

SOURCE=.\res\iny.bmp
# End Source File
# Begin Source File

SOURCE=.\res\jmp.bmp
# End Source File
# Begin Source File

SOURCE=.\res\jsr.bmp
# End Source File
# Begin Source File

SOURCE=.\res\lda.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ldx.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ldy.bmp
# End Source File
# Begin Source File

SOURCE=.\res\lsr.bmp
# End Source File
# Begin Source File

SOURCE=.\res\nop.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ora.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pha.bmp
# End Source File
# Begin Source File

SOURCE=.\res\php.bmp
# End Source File
# Begin Source File

SOURCE=.\res\pla.bmp
# End Source File
# Begin Source File

SOURCE=.\res\plp.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rol.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ror.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rti.bmp
# End Source File
# Begin Source File

SOURCE=.\res\rts.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sbc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sec.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sed.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sei.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sta.bmp
# End Source File
# Begin Source File

SOURCE=.\res\stx.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sty.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tax.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tay.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tsx.bmp
# End Source File
# Begin Source File

SOURCE=.\res\txa.bmp
# End Source File
# Begin Source File

SOURCE=.\res\txs.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tya.bmp
# End Source File
# Begin Source File

SOURCE=.\res\WinDeKikaigoV2.ico
# End Source File
# Begin Source File

SOURCE=.\res\WinDeKikaigoV2.rc2
# End Source File
# Begin Source File

SOURCE=.\res\WinDeKikaigoV2Doc.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
