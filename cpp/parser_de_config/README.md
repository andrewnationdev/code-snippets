# MINI CONFIG PARSER (C++)

## Descrição
Programa minimalista em C++ para leitura, validação e
extração de parâmetros de arquivos de configuração no
formato `chave=valor` (ex: settings.txt).

## Funcionamento
1. Leitura do Arquivo:
   - Abertura segura e leitura linha por linha via `std::ifstream`.
   - Armazenamento temporário das linhas em `std::vector<std::string>`.

2. Parsing & Validação:
   - Identificação do delimitador '=' usando `std::string::find`.
   - Separação de substrings (left/right) com `std::substr`.
   - Mapeamento direto das chaves e valores em `std::map<std::string, std::string>`.
   - Validação de integridade: interrompe e falha se houver linhas fora do padrão.

3. Saída:
   - Exibição ordenada dos pares chave-valor no console.

## Como Executar
- Certifique-se de ter o arquivo `settings.txt` no mesmo diretório do executável.
- Formato esperado no settings.txt:
    `chave1=valor1`
    `chave2=valor2`