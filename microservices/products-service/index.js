const express = require('express');
const app = express();
const port = 3001;
const fs = require('fs/promises');

app.use(express.json());

let products = [];

const isUserTokenValid = (token) => {
  return true;
}

const loadData = async () => {
  const content = await fs.readFile('products.json', 'utf-8');
  products = JSON.parse(content);
}

app.get('/', (req, res) => {
  res.send('Bem-vindo ao serviço de produtos');
});

app.get('/products', async (req, res) => {
  await loadData();
  res.json(products);
});

app.post('/register', async (req, res) => {
  const data = req.body;

  if (!data.id ||
    !data.title ||
    !data.description ||
    !data.category ||
    !data.picture_url ||
    !data.price
  ) {
    res.status(400).json({ erro: "Campos obrigatórios em falta!" });
  } else {
    products.push(data);
    await fs.writeFile('products.json', JSON.stringify(products, null, 2), 'utf-8');
    res.send({
      status: 200,
      data: products
    });
  }
});

app.delete('/delete', async (req, res) => {
  const data = req.body;

  if (!data.id && !data.user_token) {
    res.status(400).json({ erro: "ID do produto e o Token de autenticação estão faltando!" });
    return;
  }

  if (!isUserTokenValid(data.user_token)) {
    res.status(400).json({ erro: "Token de autenticação inválido. Ele é obrigatório para alterar itens." });
    return;
  }

  await loadData();

  const new_products = products.filter((p) => p.id !== data.id);
  products = [...new_products];

  await fs.writeFile('products.json', JSON.stringify(products, null, 2), 'utf-8');
  res.send({
    status: 200,
    data: products
  });
});

app.post('/edit', async (req, res) => {
  const data = req.body;

  if (!data.id ||
    !data.title ||
    !data.description ||
    !data.category ||
    !data.picture_url ||
    !data.price
  ) {
    res.status(400).json({ erro: "Campos obrigatórios em falta!" });
  } else {
    await loadData();
    let position = -1;

    for (let i = 0; i < products.length; i++) {
      if (products[i].id === data.id) {
        position = i;
        break;
      }
    }

    if (position !== -1) {
      products[position] = data;

      await fs.writeFile('products.json', JSON.stringify(products, null, 2), 'utf-8');
      res.send({
        status: 200,
        data: products
      });
    } else {
      res.status(400).json({ erro: "Produto não encontrado" });
    }
  }
});

app.listen(port, () => {
  console.log(`Serviço de produtos executando na porta ${port}`);
});
