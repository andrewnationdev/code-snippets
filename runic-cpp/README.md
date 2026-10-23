# Runic C++

O Runic C++ (.rpp) é um dialeto sintático e estilístico desenvolvido sobre a linguagem C++, projetado para permitir a escrita de código-fonte utilizando caracteres do alfabeto rúnico (Futhark). Por meio do uso de metaprogramação com o pré-processador e suporte nativo ao padrão UTF-8 (C++20), a ferramenta mapeia palavras-chave, estruturas de controle de fluxo, tipos de dados e operadores de E/S diretamente para símbolos rúnicos. Isso transforma a experiência de codificação tradicional em uma representação mística e exótica, mantendo a performance, robustez e total compatibilidade com o ecossistema C++ nativo.

Para viabilizar a execução sem a necessidade de alterar a infraestrutura dos compiladores tradicionais (como o GCC e Clang), o projeto conta com um fluxo de pré-compilação e automação via Shell Script no ambiente Linux. O sistema realiza o tratamento dos arquivos de extensão .rpp, gerenciando a substituição transparente do código para um arquivo .cpp temporário antes da geração do binário final. Essa abordagem em camadas une a criatividade da estilização rúnica ao rigor da compilação nativa, oferecendo um fluxo de desenvolvimento prático, automatizado e totalmente funcional.

```cpp
ᛁᚾᛏ ᛗᚨᛁᚾ() {
    ᛋᛏᚱᛁᚾᚴ ᛗᛖᚾᛋᚨᚴᛖᛗ = "Olá Mundo!";
    ᛒᛟᛟᛚ ᚨᛏᛁᚢᛟ = ᛏᚱᚢᛖ;

    ᛁᚠ (ᚨᛏᛁᚢᛟ == ᛏᚱᚢᛖ) {
        ᛈᚱᛁᚾᛏ << ᛗᛖᚾᛋᚨᚴᛖᛗ << ᛖᚾᛞᛚ;
    } ᛖᛚᛋᛖ {
        ᛈᚱᛁᚾᛏ << "Inativo." << ᛖᚾᛞᛚ;
    }

    ᚠᛟᚱ (ᛁᚾᛏ ᛁ = 0; ᛁ < 3; ᛁ++) {
        ᛈᚱᛁᚾᛏ << "Contagem: " << ᛁ << ᛖᚾᛞᛚ;
    }

    ᚱᛖᛏᚢᚱᚾ 0;
}
```

## STEP-BY-STEP GUIDE
1-Import `#include "runic.hpp"`
2-Write your code in a `.rpp` file
3-Run the command `./runic.sh [file].rpp [executable]`
