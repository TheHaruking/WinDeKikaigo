# Windows で機械語！

## ■ VM 仕様

### 出力

| 項目 | 内容 |
|-|-|
| 画面 サイズ | 256 x 192 |
| 画面 色数| (1bit, 2bit, 4bit) 8bit (16bit, 24bit, 32bit) |
| 画面 パレット | (未定) |
| スプライト サイズ | 8x8 |
| スプライト 枚数 | 256 |
| スプライト 要素 (4-8 bytes) | 画像ID, X座標, Y座標 (拡大, 回転, 優先度) |
| コンソール | 8x8 フォント (32 x 24) |
| コンソール 要素 | 文字コード (SHIFT-JIS, UCS2, UTF-32, UTF-8), スクロール, 色 |

### 入力

| 項目 | 内容 |
|-|-|
| ボタン | [J] [K] [;] [SPACE] [W] [A] [S] [D] (変更可能) |
| マウスボタン | 左ボタン, 右ボタン, 中ボタン, ホイール |
| マウス | 座標取得対応 |

### マシンモデル

| ビット | アドレス範囲 | 画面 (VRAM) | スプライト | コンソール | 入力 |
|-|-|-|-|-|-|-|
| 8 bit | 0x0000 <br>- 0xFFFF | 0x2000 <br>- 0xDFFF (MAX:8bit) | 0xE000 <br>- 0xE??? | 0xF000 <br>- 0xF??? | 0xF??? <br>- 0xF??? |
| 32bit | 0x00000000 <br>- 0xFFFFFFFF | 0x04000000 <br>- 0x04002FFFF (MAX:32bit) | 0x03800000<br>- 0x03800??? | 0x03400000<br>- 0x03400??? | 0x03000000<br>- 0x03000??? |

### スプライト配列 

(ひとまず現 ver では) 4 バイトで 1 スプライトを扱う。
 
ID -- XX YY

|||
|-|-|
| 1 バイト目 | 画像 ID。0 は透明な画像とする。(= 表示 ON / OFF を兼ねさせる) |
| 2 バイト目 | 未定 |
| 3 バイト目 | X 座標 |
| 4 バイト目 | Y 座標 |

### メモリマップ (8bit)

| アドレス | 内容 |
|-|-|
| 0x0000 | 空き |
| 0x1000 | 空き |
| 0x2000 | VRAM |
| 0x3000 | VRAM |
| 0x4000 | VRAM |
| 0x5000 | VRAM |
| 0x6000 | VRAM |
| 0x7000 | VRAM |
| 0x8000 | VRAM |
| 0x9000 | VRAM |
| 0xA000 | VRAM |
| 0xB000 | VRAM |
| 0xC000 | VRAM |
| 0xD000 | VRAM |
| 0xE000 | スプライト(0x???) |
| 0xF000 | コンソール (0x???), 入力 (0x???) |

|||
|-|-|
| 0xFFFA | (6502) NMI 割り込みベクタ |
| 0xFFFC | (6502) RESET 割り込みベクタ |
| 0xFFFE | (6502) IRQ/BRK 割り込みベクタ |

### VM 設定

| 項目 | 内容 |
|-|-|
| 画面拡大率 | 1x, 2x, 3x, 4x |
| キーコンフィグ | |
| パレット設定 | |

## ■ ファイル構成

将来の予定

+ 基本ソース
  - AsmViewV2.cpp
  - AsmViewV2.h
  - BinViewV2.cpp
  - BinViewV2.h
  - MainFrm.cpp
  - MainFrm.h
  - StdAfx.cpp
  - StdAfx.h
  - WinDeKikaigoV2.cpp
  - WinDeKikaigoV2.h
  - WinDeKikaigoV2Doc.cpp
  - WinDeKikaigoV2Doc.h
  - WinDeKikaigoV2View.cpp
  - WinDeKikaigoV2View.h
  - resource.h
  - WinDeKikaigoV2.rc

+ CPU 基底クラス
  - BaseEmu.cpp
  - BaseEmu.h
  - BaseEmuOutput.cpp
  - BaseEmuOutput.h
  - BaseAsmInputBar.cpp
  - BaseAsmInputBar.h
  - BaseAsmInputBarDlg.cpp
  - BaseAsmInputBarDlg.h

+ CPU 依存クラス A
  - 6502Emu.cpp (Emu6502.cpp)
  - 6502Emu.h (Emu6502.h)
  - 6502EmuOutput.cpp (Emu6502OutputV2.cpp)
  - 6502EmuOutput.h (Emu6502OutputV2.h)
  - 6502AsmInputBar.cpp (AsmInputBar.cpp)
  - 6502AsmInputBar.h (AsmInputBar.h)
  - 6502AsmInputBarDlg.cpp (AsmInputBarDlg.cpp)
  - 6502AsmInputBarDlg.h (AsmInputBarDlg.h)

+ CPU 依存クラス B	
  - ArmV4Emu.cpp
  - ArmV4Emu.h
  - ArmV4EmuOutput.cpp
  - ArmV4EmuOutput.h
  - ArmV4AsmInputBar.cpp
  - ArmV4AsmInputBar.h
  - ArmV4AsmInputBarDlg.cpp
  - ArmV4AsmInputBarDlg.h

+ 画像リソース
  - 画像\spr_000.bmp
  - 画像\spr_001.bmp
  - 画像\spr_002.bmp
  - ...
  - 画像\spr_255.bmp
  