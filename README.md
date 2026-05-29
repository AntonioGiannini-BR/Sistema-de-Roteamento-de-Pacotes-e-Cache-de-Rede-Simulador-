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

Para executar o projeto, siga os passos abaixo:

### 1. Backend (API)

Navegue até o diretório `backend` e compile a API. Certifique-se de ter a `libmicrohttpd` instalada em seu sistema.

```bash
cd backend
make api
./api
```

Isso iniciará a API em `http://localhost:8888`. O backend agora simula dados dinâmicos para o frontend.

### 2. Frontend

Em um novo terminal, navegue até o diretório `frontend` e instale as dependências e inicie o servidor de desenvolvimento:

```bash
cd frontend
npm install
npm run dev
```

O frontend será iniciado em `http://localhost:5173` (ou outra porta disponível). Abra essa URL no seu navegador.

## Mudanças Importantes de Integração

As seguintes mudanças foram implementadas para garantir a compatibilidade entre o frontend e o backend:

*   **API Dinâmica (Simulada):** O arquivo `backend/src/api_server.c` foi modificado para gerar um JSON com dados simulados que refletem o estado do sistema (pacotes, cache hits, colisões, prioridade, etc.). Isso permite que o frontend exiba informações que parecem dinâmicas, mesmo que o backend em C não esteja interagindo diretamente com as estruturas de dados em tempo real para a API.
*   **Polling no Frontend:** O hook `frontend/src/hooks/useBackend.js` foi atualizado para realizar polling a cada 2 segundos, buscando os dados mais recentes da API. Isso garante que o dashboard do frontend seja atualizado automaticamente.
*   **Consumo de Dados no Frontend:** O componente `frontend/src/App.jsx` foi ajustado para consumir os dados fornecidos pela API através do `useBackend` hook, substituindo os dados estáticos (`mockados`) anteriores. As seções de Dashboard, Pacotes, Hash, Histórico, Analytics e Logs agora exibem informações baseadas no retorno da API (ou dados padrão se a API estiver offline).

## Preservação da Qualidade e Estilo

Todas as alterações foram realizadas com o objetivo de preservar a arquitetura existente, a qualidade visual, a identidade da interface, as animações, as abas e a experiência do usuário. Nenhuma funcionalidade existente foi simplificada ou removida sem necessidade, e a organização de pastas original foi mantida.

## Autor

Antonio Giannini
Lucas Henrique



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
