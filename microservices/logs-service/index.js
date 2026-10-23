const express = require('express');
const app = express();
const port = 3000;
const fs = require('fs/promises');

app.use(express.json());

let logs = [];

const formatAsLOGString = (data) => {
  return `[${data.datetime}] [${data.type}] [${data.service_name}]: ${data.message}`;
}

app.get('/', (req, res) => {
  res.send('Bem-vindo ao serviço de LOGS de sistema');
});

app.get('/logs', async (req, res) => {
  const content = await fs.readFile('logs.json', 'utf-8');
  logs = JSON.parse(content);
  res.json(logs);
});

app.post('/register', async (req, res) => {
  const data = req.body;

  if (!data.message || !data.service_name || !data.datetime || !data.type) {
    res.status(400).json({ erro: "Campos obrigatórios em falta!" });
  } else {
    logs.push(formatAsLOGString(data));
    await fs.writeFile('logs.json', JSON.stringify(logs, null, 2), 'utf-8');
    res.send({
      status: 200,
      data: logs
    });
  }
});

app.listen(port, () => {
  console.log(`Serviço de LOGS de sistema executando na porta ${port}`);
});
