#!/bin/bash

set -e

if [ "$#" -ne 2 ]; then
    echo "Uso incorreto!"
    echo "Sintaxe: $0 <arquivo_fonte.rpp> <nome_do_executavel>"
    exit 1
fi

SOURCE="$1"
TARGET="$2"

if [ ! -f "$SOURCE" ]; then
    echo "Erro: O arquivo de origem '$SOURCE' não foi encontrado."
    exit 1
fi

TEMP_CPP="${SOURCE%.*}.cpp"

echo "-> Preparando fonte: '$SOURCE' -> '$TEMP_CPP'"
cp "$SOURCE" "$TEMP_CPP"

echo "-> Compilando '$TEMP_CPP' para gerar '$TARGET'..."
g++ -std=c++20 "$TEMP_CPP" -o "$TARGET"

rm "$TEMP_CPP"

echo "✔ Compilação concluída com sucesso: ./$TARGET"
