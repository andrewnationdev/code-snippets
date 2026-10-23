# 🧩 Microsserviço de Produtos

Microsserviço RESTful desenvolvido em Node.js com Express para a gestão de produtos, utilizando persistência assíncrona baseada em arquivos JSON (`fs/promises`).

## 🚀 Tecnologias Utilizadas
* Node.js
* Express
* Módulo `fs/promises`

## 📌 Configuração e Execução

* Instale as dependências
```bash
   npm install express
```

* Execute o serviço: `node index.js`

O serviço executará na porta 3001.

## 🔌 Endpoints da API
### 1. Verificação de Estado
 * Método: `GET`
 * Rota: `/`
 * Descrição: Retorna uma mensagem de boas-vindas do microsserviço.
 
### 2. Listar Produtos
 * Método: `GET`
 * Rota: `/products`
 * Descrição: Lê o arquivo products.json e retorna todos os produtos registrados.
 * Exemplo com curl:
   `curl -X GET http://localhost:3001/products`

### 3. Registrar Produto
 * Método: `POST`
 * Rota: `/register`
 * Descrição: Adiciona um novo produto ao array e atualiza o arquivo `products.json`.
 * Corpo da Requisição (JSON):
 ```json
 {
  "id": "prod-001",
  "title": "Teclado Mecânico RGB",
  "description": "Teclado mecânico switch blue",
  "category": "Periféricos",
  "picture_url": "[https://exemplo.com/teclado.jpg](https://exemplo.com/teclado.jpg)",
  "price": 349.99
}
```

 * Exemplo com curl:
```bash
 curl -X POST http://localhost:3001/register \
-H "Content-Type: application/json" \
-d '{"id": "prod-001", "title": "Teclado Mecânico RGB", "description": "Switch blue", "category": "Periféricos", "picture_url": "[https://exemplo.com/teclado.jpg](https://exemplo.com/teclado.jpg)", "price": 349.99}'
```

### 4. Editar Produto
 * Método: `POST` (ou `PUT`)
 * Rota: `/edit`
 * Descrição: Atualiza os dados de um produto existente com base no ID.
 * Corpo da Requisição (JSON):
 ```json
 {
  "id": "prod-001",
  "title": "Teclado Mecânico RGB Pro",
  "description": "Switch red atualizado",
  "category": "Periféricos",
  "picture_url": "[https://exemplo.com/teclado-pro.jpg](https://exemplo.com/teclado-pro.jpg)",
  "price": 399.99
}
```

 * Exemplo com curl:
```bash
   curl -X POST http://localhost:3001/edit \
-H "Content-Type: application/json" \
-d '{"id": "prod-001", "title": "Teclado Mecânico RGB Pro", "description": "Switch red", "category": "Periféricos", "picture_url": "[https://exemplo.com/teclado-pro.jpg](https://exemplo.com/teclado-pro.jpg)", "price": 399.99}'
```

### 5. Deletar Produto
 * Método: `DELETE`
 * Rota: `/delete`
 * Descrição: Remove um produto do array com base no ID, exigindo validação de token.
 * Corpo da Requisição (JSON):
 ```json
{
  "id": "prod-001",
  "user_token": "token-valido-123"
}
```

 * Exemplo com curl:
```bash
   curl -X DELETE http://localhost:3001/delete \
-H "Content-Type: application/json" \
-d '{"id": "prod-001", "user_token": "token-valido-123"}'
```
