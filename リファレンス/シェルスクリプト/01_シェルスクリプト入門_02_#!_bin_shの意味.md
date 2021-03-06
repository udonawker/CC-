# &#35;!/bin/shの意味
## シェルスクリプトの1行目

**例**<br>
<pre>
#!/bin/sh                   1行目の先頭から、#!に続いてシェルの絶対パスを書く

echo 'Hello World'
</pre>

### 解説
　シェルスクリプトの1行目には通常、&#35;!/bin/shと書きます。このように書いておくと、シェルスクリプトの実行時に、システム内部で「/binsh **シェルスクリプト名**」というコマンドが実行されます。つまり、冒頭の「hello」というシェルスクリプトの場合、./helloとコマンド入力した時に、システム上では「/bin/sh ./hello」というコマンドが実行されているのです。<br>
　/bin/shは、「hello」というファイルの中身を1行ずつ実行しますが、この時、1行目の&#35;!/bin/shの行自体は、行頭に&#35;があるため、シェルにとってはコメントとみなされ、単に無視されます。<br>
<br>
#### &#35;/bin/sh以外のスクリプト(Perlやawk)
　1行目の&#35;!/bin/shの部分に、/bin/sh以外のコマンドを書いてもかまいません。たとえば&#35;!/usr/bin/perlと書けばPerlスクリプトに、&#35;!/usr/bin/awk -fと書けばawkスクリプトになります(awkの場合は-fオプションが必要です)。Perlやawkを使用したHello Worldのスクリプトをそれぞれ**リストA、リストBに示します。これらのスクリプトも、chmod +xで実行属性を付けて実行すれば、もちろん「Hello World」と表示されます。この時、システム上ではそれぞれ「/usr/bin/perl ./perl_hello」「/usr/bin/awk -f ./awk_hello」というコマンドが実行されています。<br>

#### リストA perl_hello(PerlによるHello World)
<pre>
&#35;!/usr/bin/perl         Perlスクリプトであることを明示

print "Hello World&#92;n";  Perl文法によるprint行
</pre>

#### リストB awk_hello(awkによるHello World)
<pre>
&#35;!/usr/bin/awk -f       awkスクリプトであることを明示(-fオプションが必要)

BEGIN {
    print "Hello World"
}
</pre>

#### tailコマンドを使った変わったスクリプト
　さらに、1行目の&#35;!のところにPerlでもawkでもない、普通のコマンドを書くこともできます。一般に、&#35;!の右にとのようなコマンドを書いても、そのスクリプト実行時に、単に&#35;!のところに書いたコマンドが、スクリプトのファイル名を引数に付けて実行されるにすぎないのです。<br>
　**リストC**はtailコマンドを利用した変わったHello Worldです。この「tail_hello」を実行すると、システム上では「/usr/bin/tail -1 ./tail_hello」というコマンドが実行され、tailコマンドの-1オプションにより、tail_helloファイルの最後の1行が表示されることになります。tail_helloの最後の1行には、直接「Hello World」と書いてあるため、この文字列が直接表示されるというしくみです。<br>

#### リストC tail_hello(tailによるHello World)
<pre>
&#35;!/usr/bin/tail -1      tail -1を事項するスクリプトであることを明示
                            2行目は空行
Hello World                 最後の1行に直接メッセージを記述
</pre>

### Memo
* 1行目の&#35;!のところに各コマンドに対する引数は、1個のみ記述するようにしてください(askの-fやtailの-1など)。2個以上の引数を記述した場合の動作は、次に示すとおりOSによって異なります<br>
　→ Linuxの場合 : すべての引数がスペースを含めてつながり、全体が1個の引数とみなされる<br>
　→ FreeBSDの場合 : Linuxと同様に、すべての引数がスペースを含めてつながり、全体が1個の引数とみなされる(ただしFreeBSD 5.x以前では2個以上の引数を使用することが可能)<br>
　→ Solarisの場合 : 記述された引数のうち、1個目のみが認識される<br>
* 1行目の&#35;!のところに別のシェルスクリプト等を記述しても正しく実行されません。ここには、実行バイナリファイルを記述する必要があります。<br>
