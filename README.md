# 🚀 Routing OS Enterprise

> Sistema inteligente de roteamento de pacotes e cache de rede com dashboard enterprise, integração Frontend ↔ Backend, estruturas de dados em C e visual premium inspirado em softwares profissionais de monitoramento de rede.

---

# 🌌 Visão Geral

O **Routing OS Enterprise** é um projeto acadêmico/profissional desenvolvido com foco em:

✅ Estruturas de Dados  
✅ Sistemas Computacionais  
✅ Integração Frontend + Backend  
✅ API REST  
✅ Simulação de Redes  
✅ Visualização Analítica  
✅ Design Enterprise  

O sistema simula um ambiente real de gerenciamento de rede, processando pacotes, cache, colisões e prioridades através de algoritmos desenvolvidos em **C**, enquanto um dashboard moderno em **React** exibe todas as informações em tempo real.

---

# 🖥️ Preview do Sistema

## Frontend Dashboard
- Interface enterprise moderna
- Analytics em tempo real
- Navegação interativa
- Animações fluidas
- Design neon/cyberpunk profissional
- Gráficos dinâmicos
- Sistema responsivo

## Backend
- Processamento de pacotes
- Tabela Hash
- Fila de Prioridade
- Histórico de Processamento
- Cache de Rede
- API REST em C

---

# 🧠 Tecnologias Utilizadas

## Frontend

| Tecnologia | Uso |
|---|---|
| React | Interface |
| Vite | Build e desenvolvimento |
| JavaScript | Lógica frontend |
| CSS3 | Estilização |
| Fetch API | Comunicação com backend |

---

## Backend

| Tecnologia | Uso |
|---|---|
| Linguagem C | Processamento principal |
| libmicrohttpd | API REST |
| Estruturas de Dados | Algoritmos |
| Makefile | Automação |

---

# 📁 Estrutura do Projeto

```bash
RoutingOS/
│
├── frontend/
│   ├── src/
│   │   ├── App.jsx
│   │   ├── DashboardRede.jsx
│   │   ├── services/
│   │   ├── hooks/
│   │   └── assets/
│   │
│   ├── package.json
│   └── vite.config.js
│
├── backend/
│   ├── src/
│   │   ├── main.c
│   │   ├── api_server.c
│   │   ├── hash_table.c
│   │   ├── priority_queue.c
│   │   └── history.c
│   │
│   ├── include/
│   └── Makefile
│
└── README.md
```

---

# ⚡ Funcionalidades

# ✅ Dashboard Enterprise

- Sistema de Analytics
- Monitoramento em tempo real
- Visual premium
- Navegação dinâmica
- Interface inspirada em softwares SaaS

---

# ✅ Sistema de Pacotes

O sistema simula:

- Entrada de pacotes
- Processamento de prioridade
- Cache de rede
- Histórico
- Roteamento inteligente

---

# ✅ Tabela Hash

Implementação completa de:

- Inserção
- Busca
- Tratamento de colisão
- Organização de cache

---

# ✅ Fila de Prioridade

Pacotes são processados de acordo com:

```txt
ALTA
MÉDIA
BAIXA
```

prioridade.

---

# ✅ API REST em C

A API realiza:

- Exposição dos dados do backend
- Comunicação com React
- Integração completa

---

# 🔥 Fluxo do Sistema

```txt
Frontend React
        ↓
API REST em C
        ↓
Backend Estruturas de Dados
        ↓
Processamento dos Pacotes
```

---

# 🚀 COMO EXECUTAR O PROJETO

# 1️⃣ EXTRAIR O ZIP

Extraia o projeto:

```txt
RoutingOS_FINAL_FUNCIONAL.zip
```

---

# 2️⃣ ABRIR NO VSCODE

Abra a pasta do projeto no VSCode.

---

# 3️⃣ FRONTEND

## Entrar na pasta

```bash
cd frontend
```

---

## Instalar dependências

```bash
npm install
```

---

## Rodar frontend

```bash
npm run dev
```

---

## Abrir no navegador

```txt
http://localhost:5173
```

---

# 4️⃣ BACKEND

Abra outro terminal.

---

## Entrar na pasta backend

```bash
cd backend
```

---

## Compilar backend

```bash
make
```

---

## Rodar sistema

```bash
./sistema
```

---

# 5️⃣ API REST

## Instalar Homebrew (Mac)

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

---

## Adicionar Homebrew ao terminal

```bash
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zprofile
```

```bash
eval "$(/opt/homebrew/bin/brew shellenv)"
```

---

## Instalar biblioteca da API

```bash
brew install libmicrohttpd
```

---

## Compilar API

```bash
gcc src/api_server.c -I/opt/homebrew/include -L/opt/homebrew/lib -lmicrohttpd -o api
```

---

## Rodar API

```bash
./api
```

---

# 🌐 API ONLINE

Se tudo funcionar corretamente:

```txt
API ONLINE: http://localhost:8888
```

---

# 🧪 Como Testar a Integração

Abra:

```txt
http://localhost:8888
```

Você verá:

```json
{
  "packets":12,
  "cacheHits":8,
  "collisions":2,
  "priority":6
}
```

Isso confirma que:

```txt
React ← API ← Backend C
```

estão conectados.

---

# 📊 Funcionalidades Visuais

## Dashboard
- Cards animados
- Sidebar interativa
- Analytics
- Logs
- Histórico
- Status de rede
- Indicadores visuais

---

# 🧱 Estruturas de Dados Implementadas

## ✔️ Tabela Hash

Utilizada para:
- Cache de rede
- Busca rápida
- Armazenamento eficiente

---

## ✔️ Fila de Prioridade

Utilizada para:
- Controle de processamento
- Ordenação de pacotes

---

## ✔️ Lista Encadeada

Utilizada para:
- Histórico de operações

---

# 🎨 Design do Sistema

O sistema utiliza:

✅ Neon UI  
✅ Dark Theme  
✅ Glassmorphism  
✅ Cyberpunk Style  
✅ Enterprise Dashboard  
✅ Motion UI  

Inspirado em:
- Datadog
- Grafana
- Vercel
- Cisco Dashboards
- Cybersecurity SaaS

---

# 📚 Objetivos Acadêmicos

Este projeto demonstra:

- Modularização
- Integração de sistemas
- Estruturas de dados
- Desenvolvimento Full Stack
- APIs REST
- Visualização computacional
- Simulação de redes

---

# 👨‍💻 Desenvolvedores

**Antonio Giannini**
**Lucas Henrique**

Projeto desenvolvido para fins:
- acadêmicos
- portfólio
- estudo de estruturas de dados
- integração frontend/backend

---

# ⭐ Possíveis Melhorias Futuras

- Banco de dados real
- WebSockets
- Autenticação
- Docker
- Deploy em nuvem
- Monitoramento em tempo real
- IA para roteamento inteligente
- Logs persistentes

---

# 🏁 Conclusão

O **Routing OS Enterprise** é um sistema completo que integra:

✅ Backend em C  
✅ API REST  
✅ Frontend React  
✅ Estruturas de Dados  
✅ Dashboard Premium  
✅ Integração Full Stack  

representando um projeto robusto e profissional voltado para monitoramento e roteamento inteligente de redes.
