const express = require('express');
const { resolve } = require('path');

const app = express();
const port = 3010;

app.use(express.json());
app.use(express.static('static'));

const users = [
  {
    username: 'abcdef',
    password: '12345',
  },
];

const checkUserDataAndLogin = (username, password) => {
  for (const user of users) {
    if (user.username === username && user.password === password) {
      let JWT =
        'eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJzdWIiOiIxMjM0NTY3ODkwIiwibmFtZSI6IkFuZHJldyIsImlhdCI6MTcwMDAwMDAwMH0.SflKxwRJSMeKKF2QT4fwpMeJf36POk6yJV_adQssw5c';
      return { token: JWT, user_id: '1234567890', status: 200, message: 'OK' };
    }
  }

  return {
    token: null,
    user_id: null,
    status: 401,
    message: 'Login failed. Invalid credentials',
  };
};

app.post('/login', (req, res) => {
  const user = req.body;

  if (user && user.user_name && user.user_pwd) {
    const result = checkUserDataAndLogin(user.user_name, user.user_pwd);
    return res.status(result.status).json(result);
  }

  return res.status(400).json({ message: 'Bad request. Missing credentials.' });
});

app.get('/', (req, res) => {
  res.sendFile(resolve(__dirname, 'pages/index.html'));
});

app.listen(port, () => {
  console.log(`Serviço auth-service rodando na porta ${port}`);
});
