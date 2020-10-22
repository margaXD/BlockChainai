## BlockChainai
# Hash generatoriaus kūrimas (v0.1)
# Pseudokodas:
Begin<br/>
  Input file name or input<br/>
  Read file or input<br/>
  Gather information<br/>
    - Number of words in document<br/>
    - ASCII sum of all the characters in document<br/>
    - Number of characters in document<br/>
    - Number of letter a in document<br/>
    - Number of letter e in document<br/>
  Create a unique seed from this information<br/>
  Hash the unique seed<br/>
End
# Analize:
1. Sukurtas failas, kuriame yra zodis Lietuva!<br/>
Hashas gaunamas toks: https://prnt.sc/uvosss<br/>
Laikas - 0.00034s<br/>
Kitame faile zodis Lietuva (be sauktuko)<br/>
hashas gaunamas toks: https://prnt.sc/uvouek<br/>
Laikas - 0.00033s<br/>
2. Sukurtas 19KB dydzio failas, pilnas simboliu<br/>
Hashas gautas toks: https://prnt.sc/uvowq5<br/>
Laikas - 0.05248s<br/>
Vidury failo iterpta A raide<br/>
Hashas gautas toks: https://prnt.sc/uvoxfd<br/>
Laikas - 0.05122s<br/>
3. Sukurtas tuscias failas<br/>
Laikas - 0.000129700s<br/>
4. Sukurtas 25k stringu po 10 simboliu poru failas<br/>
Laikas - 19.307261s<br/>
Koliziju nerasta.
5. Sukurtas 25k stringu po 100 simboliu poru failas<br/>
Laikas - 20.524706<br/>
Koliziju nerasta.
# Kodo efektyvumas lyginant su SHA256
2. SHA256 veikia ir greiciau, ir geriau hashuoja, negu sis kodas.
3. Hash turi fixed ilgi, del to kodas nera labai taisyklingas
# Isvados:
1. Kodas nera labai taisyklingas ir nelabai gerai hashuoja
2. Mazu inputu kodas nehashuoja
3. SHA256 visais atvejais geresnis nei sis kodas

# Kodo keitimai:
10/15/2020 - Pakoreguotas header.cpp ir main.cpp failai.<br/>
10/22/2020 - Pakoreguotas header.cpp ir main.cpp failai. Prideta nauju txt failu.
