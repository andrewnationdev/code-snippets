# Auth Service (Microsserviço de Autenticação)

Microsserviço simples de autenticação desenvolvido em Node.js e Express, utilizado para validação de credenciais de usuário e emissão de tokens JWT (fictícios).

## 🚀 Tecnologias Utilizadas

- Node.js
- Express.js

## 📌 Funcionalidades

- Rota de login via HTTP POST com validação de credenciais.
- Retorno de payload JSON contendo o token JWT e status da requisição.

## 🛠️ Como Executar o Projeto

Instalar as dependências:

`npm install express`

Iniciar o servidor:

`node index.js`

O serviço estará rodando na porta 3010: `http://localhost:3010`

## 📬 Endpoints

### POST /login

Realiza a autenticação do usuário.

Body (JSON):

```
{
"user_name": "abcdef",
"user_pwd": "12345"
}
```

Resposta de Sucesso (200 OK):

```
{
"token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9...",
"user_id": "1234567890",
"status": 200,
"message": "OK"
}
```

Resposta de Erro (401 Unauthorized):

```
{
"token": null,
"user_id": null,
"status": 401,
"message": "Login failed. Invalid credentials"
}
```
