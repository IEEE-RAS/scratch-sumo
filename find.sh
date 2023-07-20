#!/bin/bash

busca() { #busca a frase e imprime o caminho 
    caminho=$1
    frase=$2

    if grep -qF "$frase" "$caminho"; then
        echo $caminho
    fi
}

verificaDiretorio() { #ve diretorio e subdiretorio
    diretorio=$1
    frase=$2

    for i in "$diretorio"/*; do
        if [ -d "$i" ]; then #eh um diretorio
            verificaDiretorio "$i" "$frase"
        elif [ -f "$i" ]; then #eh um arquivo 
            if [[ $i == *.js ]]; then
                busca "$i" "$frase" #faz a busca da frase 
            fi
        fi
    done
}

echo "frase:"
read frase
diretorioAtual=$(pwd)
verificaDiretorio "$diretorioAtual" "$frase"
