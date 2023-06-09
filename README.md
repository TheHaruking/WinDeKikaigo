# Windows で機械語！

![image](https://user-images.githubusercontent.com/23455187/236684416-b95c07b4-371b-407a-8319-91d3a2188aba.png)

## このソフトは？

手軽に機械語を味わうためのソフトウェアです。  
ネイティブに実行するのではなく、6502 エミュレーションを通して機械語プログラムを実行する作りになっています。  

現在アルファ版です。  
万が一このソフトウェアを実行される場合はテスト環境で実行ください。  

## ビルド環境

- Visual C++ 6.0
  - Visual Studio 2019 までであればプロジェクトのアップグレードも可能です。(ビルドエラーが出るので、プロジェクト設定の変更は必要です。)  
    (Visual Studio 2022 以降、Visual C++ 6.0 ワークスペース (.dsw) および プロジェクト (.dsp) ファイルのアップグレードはサポートされなくなりました。)

## 使い方

サンプルを動かしてみてください。  

![image](https://user-images.githubusercontent.com/23455187/236684457-482ee2a6-b193-42e9-8166-dd8f8e28e793.png)

1. [開く] のアイコンから Release に同梱のサンプル (.bin) を開きます  
2. 仮想マシンウインドウ (★のアイコン) を開きます  
3. [>>] アイコンをクリックし、実行します  

MOS 6502 のシミュレータが動作し、レジスタ情報ペインや仮想マシンウインドウが動き始めます。  

(詳細はTODO)  

---

## ■ 仮想マシン機能 仕様

### 出力

| 項目 | 内容 |
|-|-|
| 画面 サイズ | 256 x 192 |
| 画面 色数| 8bit (256 色) |
| スプライト 定義枚数 | 256 枚 |
| スプライト 表示枚数 | 64 枚 |
| スプライト 要素 (4-8 bytes) | 画像ID, X座標, Y座標 |


### メモリマップ

| アドレス | 内容 |
|-|-|
| 0x0000 - 0x1FFF | 空き (ただし 0x0100 - 0x01FF は除く) |
| 0x2000 - 0xDFFF | VRAM |
| 0xE000 - 0xE3FF | スプライト管理領域 |
| 0xE400 - 0xE7FF | パレット管理領域 |
| 0xE800 - 0xFFFF | (予約) |

### メモリマップ (詳細)

| アドレス | 内容 | 各バイトの意味 | 説明
|-|-|-|-|
| 0x0000 - 0x00FF | (空き) | - | ユーザー領域 |
| 0x0100 - 0x01FF | 6502 スタック領域 | - | CPU がスタックとして使用する領域 |
| 0x0200 - 0x1FFF | (空き) | - | ユーザー領域 |
| 0x2000 - 0xDFFF | VRAM | 色 id | 画面の描画元となるメモリ領域。色 id を指定するとアドレスに対応した画素の色が変わる。色 id は 0x00 - 0xFF の指定が出来る。色 id が参照する色そのものはパレット領域を書き換えることで設定可能。 |
| 0xE000 - 0xE3FF | スプライト | 1バイト目 : 画像id<br>2バイト目 : (未使用)<br>3バイト目 : X座標<br>4バイト目 : Y座標 | スプライトの画像、および座標の設定が可能。1要素は4バイトで構成される (計 256 要素)。画像id は 0x00 - 0x0F の範囲しか指定できない。 |
| 0xE400 - 0xE7FF | パレット | 1バイト目 : 赤<br>2バイト目 : 緑<br>3バイト目 : 青<br>4バイト目 : (未使用)| 色 id で参照される色を変更可能。<br>1要素は4バイトで構成される (計 256 要素)。 |
| 0xE800 - 0xEFFF | (予約) | - | 予約領域 |
| 0xF000 - 0xFFF9 | (予約) | - | 予約領域 |
| 0xFFFA - 0xFFFF | 6502 割り込みベクタ | 1-2バイト目: NMI<br> 3-4バイト目: RESET<br>5-6バイト目: IRQ/BRK | 6502 が参照する領域 (ただし未実装。) |

## ■ 制限事項

+ 下記は実装されません
  - クロック単位でのエミュレーション
  - デシマルモード
  - 未定義命令
