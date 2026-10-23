# 🧩 Sistema de Registro de Logs

Microsserviço desenvolvido em Node.js com Express para captação, validação e persistência estruturada de logs do sistema para a prática de desenvolvimento de aplicações com microsserviços.

## 🛠 Tecnologias
- Node.js & Express
- Módulo nativo `fs/promises` para persistência
- Middlewares nativos de parsing (`express.json()`)

## 🚀 Endpoints

### 1. Consultar Logs (`GET /logs`)
Retorna a lista completa de logs armazenados.
- **URL:** `http://localhost:3000/logs`
- **Método:** `GET`

### 2. Registar Novo Log (`POST /register`)
Valida e adiciona um novo registo de log estruturado.
- **URL:** `http://localhost:3000/register`
- **Método:** `POST`
- **Headers:** `Content-Type: application/json`
- **Body Exemplo:**
```json
{
  "datetime": "2026-10-11T14:05:00.000Z",
  "message": "User session initialized successfully.",
  "type": "INFO",
  "service_name": "auth-service"
}
```

## 💻 Como Executar
- Instale as dependências: `npm install`
- Inicie com hot-reload: `node --watch index.js`
