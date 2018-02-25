# 『ふつうのLinuxプログラミング』第2版 サンプルコード

このディレクトリには『ふつうのLinuxプログラミング第2版』の
サンプルコード (+ α) が収録されています。

サポートサイト: http://i.loveruby.net/stdlinux2/

## 必要環境

プログラムをビルドするにはLinuxとgcc、GNU makeが必要です。
動作確認は以下の環境で行いました。

- Ubuntu Linux Desktop 16.04 LTS
- CentOS 7.3

## ビルド方法

このディレクトリにcdし、コマンドラインでmakeコマンドを実行するとすべてのプログラムをビルドできます。
make test でテストを実行します。

## ライセンス

このディレクトリに含まれるソースコードはすべて青木峰郎が
著作権を保持しており、MITライセンスに基きライセンスします。
即ち、目的や対価の有無に関らず変更・再配布・他のプログラム
への組み込みなどを許可します。ただしこのプログラムを利用した
結果生じたトラブルなどについては、いかなる場合も著者ならびに
出版社は責任を負いかねます。

青木峰郎 / Minero Aoki

# ソースコード一覧

## 第1章
<dl>
<dt>hello.c</dt>
<dd>ありがちなHello, World!</dd>

<dt>args.c</dt>
<dd>コマンドライン引数を表示するプログラム</dd>

<dt>segv.c</dt>
<dd>NULLポインタを参照するだけのプログラム。
確実にsegmentation faultを起こす。</dd>

<dt>echo.c</dt>
<dd>簡単なechoコマンド。</dd>
</dl>

## 第4章
<dl>
<dt>bell.c</dt>
<dd>端末のベルを鳴らすプログラム</dd>
</dl>

## 第5章
<dl>
<dt>cat.c</dt>
<dd>簡単なcatコマンド (システムコール版)</dd>

<dt>cat0.c</dt>
<dd>cat.cからエラー処理を取り除いたコード</dd>

<dt>cat3.c</dt>
<dd>問題5-1の解答例。
コマンドライン引数がないときはstdinを読むcatコマンド</dd>

<dt>wc-l-syscall.c</dt>
<dd>問題5-2の解答例。
標準入力からテキストを読み込み、その行数を表示する。</dd>
</dl>

## 第6章
<dl>
<dt>cat2.c</dt>
<dd>stdioを使ったcatコマンド</dd>

<dt>getcperf.c</dt>
<dd>fgetcとgetcの速度を比較するためのプログラム。
何もコマンドライン引数を付けないとgetcを使い、
コマンドライン引数で「f」を渡すとfgetcを使う。</dd>

<dt>feof-bug.c</dt>
<dd>feofを使ったときに起こる有名なバグを確認するコード。
このプログラムの標準入力にテキストファイルをリダイレクトして実行すると、
最後の行が 2 回表示される。</dd>

<dt>cat-escape.c</dt>
<dd>問題6-1の解答例。
タブを「\t」、改行を「$」+ 改行で表示するcatコマンド</dd>

<dt>wc-l-stdio.c</dt>
<dd>問題6-2の解答例。
標準入力からテキストを読み込み、その行数を表示する。</dd>

<dt>cat5.c</dt>
<dd>問題6-3の解答例。
freadとfwriteを使ったcatコマンド。</dd>
</dl>

## 第7章
<dl>
<dt>head.c</dt>
<dd>簡単なheadコマンド。stdinのみ読む。</dd>

<dt>head2.c</dt>
<dd>簡単なheadコマンド。コマンドライン引数のファイルも読む。</dd>

<dt>head3.c</dt>
<dd>簡単なheadコマンド。
getoptでコマンドラインオプションを解析する例。</dd>

<dt>head4.c</dt>
<dd>簡単なheadコマンド。
getopt_longでコマンドラインオプションを解析する例。</dd>

<dt>gdb/*</dt>
<dd>gdbのテストに使ったファイル。</dd>

<dt>cat4.c</dt>
<dd>問題7-1の解答例。
-eオプションでcat-escape.cと同じ効果を発揮する
catコマンド。</dd>

<dt>tail.c</dt>
<dd>問題7-2の解答例。
簡単なtailコマンド（出力行数固定）。</dd>
</dl>

## 第8章
<dl>
<dt>grep.c</dt>
<dd>8章で作成したgrepコマンド</dd>

<dt>array.c</dt>
<dd>文字列と文字の配列が等しいことを確認するコード</dd>

<dt>wgrep.c</dt>
<dd>wchar を使ってマルチバイト文字にも対応した grep コマンド。
固定文字列しか検索できない。</dd>

<dt>grep2.c</dt>
<dd>問題 8-1の解答例。
-iオプションと-vオプションのついたgrepコマンド。</dd>

<dt>slice.c</dt>
<dd>問題8-2の解答例。
マッチした部分を出力する。
</dd>
</dl>

## 第10章
<dl>
<dt>ls.c</dt>
<dd>簡単なlsコマンド。</dd>

<dt>catdir.c</dt>
<dd>opendirを使わずディレクトリを読むコマンド。
./catdir . | strings とするとなんとなくlsっぽい表示ができる。</dd>

<dt>mkdir.c</dt>
<dd>簡単なmkdirコマンド。mkdir(2)の使用例。</dd>

<dt>rmdir.c</dt>
<dd>簡単なrmdirコマンド。rmdir(2)の使用例。</dd>

<dt>ln.c</dt>
<dd>簡単なlnコマンド。link(2)の使用例。</dd>

<dt>symlink.c</dt>
<dd>簡単なln -sコマンド。symlink(2)の使用例。</dd>

<dt>rm.c</dt>
<dd>簡単なrmコマンド。unlink(2)の使用例。</dd>

<dt>mv.c</dt>
<dd>簡単なmvコマンド。rename(2)の使用例。</dd>

<dt>stat.c</dt>
<dd>コマンドライン引数で指定されたファイルの付帯情報を表示する。
lstat(2)の使用例。</dd>

<dt>touch.c</dt>
<dd>簡単なtouchコマンド。utime(2)の使用例。
このコマンドは時刻を更新するだけで、ファイルを作る機能はない。</dd>

<dt>chmod.c</dt>
<dd>簡単なchmodコマンド。chmod(2)の使用例。</dd>

<dt>chown.c</dt>
<dd>簡単なchownコマンド。chown(2)とgetpwnam(3) の使用例。</dd>

<dt>chgrp.c</dt>
<dd>簡単なchgrpコマンド。chgrp(2)の使用例。</dd>

<dt>traverse.c</dt>
<dd>問題10-1の解答例。
コマンドライン引数で指定したディレクトリをトラバースして中にあるファイルを表示するプログラム。
</dd>

<dt>mkpath.c</dt>
<dd>問題10-3の解答例。
複数階層のディレクトリツリーを再帰的に作成する。
</dd>
</dl>

## 第11章
<dl>
<dt>mapwrite.c</dt>
<dd>mmap(2) のテストプログラム。</dd>

<dt>shlib/*</dt>
<dd>共有ライブラリを作成する例 [Linux only]</dd>

<dt>link/*</dt>
<dd>ライブラリのダイナミックリンクとダイナミックロードの例 [Linux only]</dd>

<dt>tail2.c</dt>
<dd>問題11-1の解答例。
簡単なtailコマンド（出力行数がコマンドライン引数で指定可能）。</dd>
</dl>

## 第12章
<dl>
<dt>exec.c</dt>
<dd>exec族のテストコード。</dd>

<dt>spawn.c</dt>
<dd>コマンドライン引数で渡されたコマンドを実行する。</dd>

<dt>dupread.c</dt>
<dd>dup(2)のテストプログラム。</dd>

<dt>sh1.c</dt>
<dd>問題12-2の解答例。
ごく簡単なシェル。</dd>

<dt>sh2.c</dt>
<dd>問題12-3の解答例。
パイプとリダイレクトを実装したシェル。</dd>
</dl>

## 第13章
<dl>
<dt>sig.c</dt>
<dd>signal(2) のテストプログラム。SIGINT を待つだけ。</dd>

<dt>sigqueue-test.c</dt>
<dd>シグナルがキューイングされるかテストするプログラム。
Linux では、プログラムが起動したあとに素早く 5 回
Ctrl-C を打っても (5 回シグナルを送っても) メッセー
ジは 2 回しか表示されない。つまり残り 3 つは失われ
たということ。</dd>

<dt>isatty.c</dt>
<dd>stdin, stdout, stderr のそれぞれについて、
端末かどうか判定する。</dd>

<dt>trap.c</dt>
<dd>問題 13-1 の解答例。
SIGINT (Ctrl-C による割り込み) を受けたらメッセージを
出して終了する。</dd>
</dl>

## 第14章
<dl>
<dt>pwd.c</dt>
<dd>簡単なpwdコマンド。定数を使う。</dd>

<dt>pwd2.c</dt>
<dd>簡単なpwdコマンド。自分でバッファの長さを調節する。</dd>

<dt>pwd3.c</dt>
<dd>簡単なpwdコマンド。GNU libc特有のgetcwd()の機能を使う。 [Linux Only]</dd>

<dt>showenv.c</dt>
<dd>getenv(3) のテストプログラム。
コマンドライン引数で指定された環境変数の値を表示する。
env.c も参照。</dd>

<dt>env.c</dt>
<dd>簡単なenvコマンド。すべての環境変数を表示する。</dd>

<dt>user.c</dt>
<dd>コマンドライン引数で指定したユーザのユーザ ID を表示する。
getpwnam(3) の使用例。</dd>

<dt>id.c</dt>
<dd>簡単なidコマンド。user.c も参照。</dd>

<dt>timefmt.c</dt>
<dd>時刻 API のテストプログラム。</dd>

<dt>strftime.c</dt>
<dd>strftime(3) のテストプログラム。</dd>

<dt>ls2.c</dt>
<dd>問題14-3の解答例。
簡単なlsコマンド。ファイルのオーナーと最終更新時刻も表示する。</dd>
</dl>

## 第15章
<dl>
<dt>daytime.c</dt>
<dd>daytimeクライアント。</dd>

<dt>daytimed.c</dt>
<dd>daytimeサーバ。
書籍で書いたのと同じ理由によりIPv4専用。</dd>
</dl>

## 第16章
<dl>
<dt>httpd.c</dt>
<dd>本章で作成したお手軽HTTPサーバ。
stdinしか読めない。
</dd>
</dl>

## 第17章
<dl>
<dt>httpd2.c</dt>
<dd>本章で作成したお手軽HTTPサーバ。
自分でデーモン化とソケット接続が可能。</dd>

<dt>logging.c</dt>
<dd>syslog(3)のテストプログラム。</dd>
</dl>

## 第18章
<dl>
<dt>make/*</dt>
<dd>makeとMakefileの例</dd>
</dl>
