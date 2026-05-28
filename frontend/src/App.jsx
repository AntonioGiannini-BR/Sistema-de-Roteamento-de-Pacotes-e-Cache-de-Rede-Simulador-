import { useState, useEffect } from "react"

export default function App() {
  const [selectedMenu, setSelectedMenu] =
    useState("Dashboard")

  const [mousePosition, setMousePosition] =
    useState({ x: 0, y: 0 })

  useEffect(() => {
    const handleMouseMove = (e) => {
      setMousePosition({
        x: e.clientX,
        y: e.clientY,
      })
    }

    window.addEventListener(
      "mousemove",
      handleMouseMove
    )

    return () =>
      window.removeEventListener(
        "mousemove",
        handleMouseMove
      )
  }, [])

  const globalStyles = `
  @keyframes fadeSlide {
    from {
      opacity: 0;
      transform: translateY(15px);
    }

    to {
      opacity: 1;
      transform: translateY(0px);
    }
  }
  `

  return (
    <>
      <style>{globalStyles}</style>

      <div
        style={{
          background: "#04070d",
          minHeight: "100vh",
          color: "white",
          fontFamily: "Inter, sans-serif",
          display: "flex",
          overflow: "hidden",
          position: "relative",
        }}
      >
        {/* GLOW FOLLOW MOUSE */}

        <div
          style={{
            position: "fixed",
            top: mousePosition.y - 200,
            left: mousePosition.x - 200,
            width: "400px",
            height: "400px",
            borderRadius: "50%",
            background:
              "radial-gradient(circle,rgba(0,229,255,0.12),transparent 70%)",
            pointerEvents: "none",
            transition: "0.15s",
            filter: "blur(40px)",
            zIndex: 0,
          }}
        />

        {/* SIDEBAR */}

        <div
          style={{
            width: "270px",
            background:
              "linear-gradient(180deg,#07111f,#04070d)",
            borderRight:
              "1px solid rgba(0,255,255,0.08)",
            padding: "25px",
            position: "relative",
            zIndex: 2,
          }}
        >
          {/* LOGO */}

          <div
            style={{
              display: "flex",
              alignItems: "center",
              gap: "15px",
              marginBottom: "50px",
            }}
          >
            <div
              style={{
                width: "55px",
                height: "55px",
                borderRadius: "18px",
                background:
                  "linear-gradient(135deg,#00e5ff,#0066ff)",
                display: "flex",
                alignItems: "center",
                justifyContent: "center",
                fontWeight: "900",
                fontSize: "26px",
                boxShadow:
                  "0 0 30px rgba(0,229,255,0.5)",
              }}
            >
              S
            </div>

            <div>
              <h1
                style={{
                  fontSize: "28px",
                  margin: 0,
                }}
              >
                ROUTING OS
              </h1>

              <p
                style={{
                  color: "#7c8aa5",
                  margin: 0,
                  fontSize: "14px",
                }}
              >
                Network System
              </p>
            </div>
          </div>

          {/* MENU */}

          {[
            "Dashboard",
            "Pacotes",
            "Hash",
            "Histórico",
            "Analytics",
            "Logs",
          ].map((item) => (
            <MenuItem
              key={item}
              title={item}
              active={
                selectedMenu === item
              }
              onClick={() =>
                setSelectedMenu(item)
              }
            />
          ))}
        </div>

        {/* MAIN */}

        <div
          style={{
            flex: 1,
            padding: "35px",
            position: "relative",
            zIndex: 2,
          }}
        >
          {/* HEADER */}

          <div
            style={{
              display: "flex",
              justifyContent:
                "space-between",
              alignItems: "center",
              marginBottom: "35px",
            }}
          >
            <div>
              <h1
                style={{
                  fontSize: "56px",
                  marginBottom: "10px",
                }}
              >
                System
                <span
                  style={{
                    color: "#00e5ff",
                  }}
                >
                  {" "}
                  Overview
                </span>
              </h1>

              <p
                style={{
                  color: "#7c8aa5",
                }}
              >
                Sistema inteligente de
                roteamento
              </p>
            </div>

            <div
              style={{
                background: "#0a101c",
                borderRadius: "22px",
                padding: "20px",
                border:
                  "1px solid rgba(0,255,255,0.08)",
              }}
            >
              <p
                style={{
                  color: "#00ff99",
                  fontWeight: "700",
                }}
              >
                ● ONLINE
              </p>
            </div>
          </div>

          {/* DASHBOARD */}

          {selectedMenu ===
            "Dashboard" && (
            <div
              style={{
                animation:
                  "fadeSlide 0.5s ease",
              }}
            >
              <div
                style={{
                  display: "grid",
                  gridTemplateColumns:
                    "repeat(4,1fr)",
                  gap: "20px",
                  marginBottom: "25px",
                }}
              >
                <Card
                  title="Pacotes"
                  value="12"
                />

                <Card
                  title="Cache Hits"
                  value="8"
                />

                <Card
                  title="Colisões"
                  value="2"
                />

                <Card
                  title="Prioridade"
                  value="6"
                />
              </div>

              <Panel title="Análise de Tráfego">
                <div
                  style={{
                    height: "300px",
                    borderRadius: "25px",
                    background:
                      "linear-gradient(180deg,#06111c,#04070d)",
                    overflow: "hidden",
                  }}
                >
                  <svg
                    width="100%"
                    height="100%"
                    viewBox="0 0 1000 300"
                    preserveAspectRatio="none"
                  >
                    <path
                      d="
                    M0,250
                    C120,120
                    220,200
                    340,160
                    C450,120
                    550,40
                    700,90
                    C820,120
                    920,240
                    1000,160
                  "
                      stroke="#00e5ff"
                      strokeWidth="6"
                      fill="none"
                    />

                    <path
                      d="
                    M0,250
                    C120,120
                    220,200
                    340,160
                    C450,120
                    550,40
                    700,90
                    C820,120
                    920,240
                    1000,160
                    L1000,300
                    L0,300
                  "
                      fill="rgba(0,229,255,0.15)"
                    />
                  </svg>
                </div>
              </Panel>
            </div>
          )}

          {/* PACOTES */}

          {selectedMenu ===
            "Pacotes" && (
            <div
              style={{
                animation:
                  "fadeSlide 0.5s ease",
              }}
            >
              <Panel title="Fila de Prioridade">
                <QueueItem
                  title="Pacote #102"
                  value="ALTA"
                  color="#ff4444"
                />

                <QueueItem
                  title="Pacote #103"
                  value="MÉDIA"
                  color="#ffcc00"
                />

                <QueueItem
                  title="Pacote #101"
                  value="BAIXA"
                  color="#00ff99"
                />
              </Panel>
            </div>
          )}

          {/* HASH */}

          {selectedMenu ===
            "Hash" && (
            <div
              style={{
                animation:
                  "fadeSlide 0.5s ease",
              }}
            >
              <Panel title="Tabela Hash">
                <HashItem text="[0] → NULL" />

                <HashItem text="[1] → IP1 → IP2" />

                <HashItem text="[2] → IP3" />

                <HashItem text="[3] → NULL" />
              </Panel>
            </div>
          )}

          {/* HISTÓRICO */}

          {selectedMenu ===
            "Histórico" && (
            <div
              style={{
                animation:
                  "fadeSlide 0.5s ease",
              }}
            >
              <Panel title="Histórico">
                <HistoryRow
                  packet="102"
                  ip="10.0.0.5"
                  status="CACHE HIT"
                />

                <HistoryRow
                  packet="103"
                  ip="192.168.0.1"
                  status="CACHE MISS"
                />

                <HistoryRow
                  packet="104"
                  ip="172.16.254.1"
                  status="CACHE HIT"
                />
              </Panel>
            </div>
          )}

          {/* ANALYTICS */}

          {selectedMenu ===
            "Analytics" && (
            <div
              style={{
                animation:
                  "fadeSlide 0.5s ease",
                display: "grid",
                gridTemplateColumns:
                  "repeat(3,1fr)",
                gap: "20px",
              }}
            >
              <Card
                title="CPU"
                value="42%"
              />

              <Card
                title="RAM"
                value="68%"
              />

              <Card
                title="PING"
                value="12ms"
              />
            </div>
          )}

          {/* LOGS */}

          {selectedMenu ===
            "Logs" && (
            <div
              style={{
                animation:
                  "fadeSlide 0.5s ease",
              }}
            >
              <Panel title="Logs do Sistema">
                <LogItem
                  text="Pacote processado"
                  color="#00ff99"
                />

                <LogItem
                  text="Cache hit detectado"
                  color="#00e5ff"
                />

                <LogItem
                  text="Colisão detectada"
                  color="#ffcc00"
                />

                <LogItem
                  text="Rede sincronizada"
                  color="#00ff99"
                />
              </Panel>
            </div>
          )}
        </div>
      </div>
    </>
  )
}

function MenuItem({
  title,
  active,
  onClick,
}) {
  return (
    <div
      onClick={onClick}
      onMouseEnter={(e) => {
        e.currentTarget.style.transform =
          "translateX(6px)"
      }}
      onMouseLeave={(e) => {
        e.currentTarget.style.transform =
          "translateX(0px)"
      }}
      style={{
        padding: "18px 22px",
        borderRadius: "18px",
        marginBottom: "12px",
        background: active
          ? "linear-gradient(90deg,#00e5ff22,#00e5ff11)"
          : "transparent",
        color: active
          ? "#00e5ff"
          : "#d1d5db",
        cursor: "pointer",
        fontWeight: "600",
        transition: "0.3s",
      }}
    >
      {title}
    </div>
  )
}

function Card({
  title,
  value,
}) {
  return (
    <div
      onMouseEnter={(e) => {
        e.currentTarget.style.transform =
          "translateY(-8px) scale(1.02)"

        e.currentTarget.style.boxShadow =
          "0 0 40px rgba(0,229,255,0.15)"
      }}
      onMouseLeave={(e) => {
        e.currentTarget.style.transform =
          "translateY(0px)"

        e.currentTarget.style.boxShadow =
          "none"
      }}
      style={{
        background:
          "linear-gradient(180deg,#0a101c,#060b14)",
        borderRadius: "30px",
        padding: "28px",
        border:
          "1px solid rgba(0,255,255,0.08)",
        transition: "0.35s",
        cursor: "pointer",
      }}
    >
      <p
        style={{
          color: "#7c8aa5",
          marginBottom: "20px",
        }}
      >
        {title}
      </p>

      <h1
        style={{
          fontSize: "52px",
          color: "#00e5ff",
        }}
      >
        {value}
      </h1>
    </div>
  )
}

function Panel({
  title,
  children,
}) {
  return (
    <div
      onMouseEnter={(e) => {
        e.currentTarget.style.transform =
          "translateY(-5px)"
      }}
      onMouseLeave={(e) => {
        e.currentTarget.style.transform =
          "translateY(0px)"
      }}
      style={{
        background:
          "linear-gradient(180deg,#0a101c,#060b14)",
        borderRadius: "35px",
        padding: "30px",
        border:
          "1px solid rgba(0,255,255,0.08)",
        boxShadow:
          "0 0 40px rgba(0,229,255,0.06)",
        transition: "0.3s",
      }}
    >
      <h2
        style={{
          marginBottom: "25px",
        }}
      >
        {title}
      </h2>

      {children}
    </div>
  )
}

function QueueItem({
  title,
  value,
  color,
}) {
  return (
    <div
      style={{
        padding: "20px",
        borderRadius: "18px",
        background: "#0b1320",
        marginBottom: "15px",
        display: "flex",
        justifyContent:
          "space-between",
      }}
    >
      <span>{title}</span>

      <span
        style={{
          color,
          fontWeight: "800",
        }}
      >
        {value}
      </span>
    </div>
  )
}

function HashItem({
  text,
}) {
  return (
    <div
      style={{
        padding: "18px",
        borderRadius: "18px",
        background: "#0b1320",
        marginBottom: "12px",
        fontFamily: "monospace",
      }}
    >
      {text}
    </div>
  )
}

function HistoryRow({
  packet,
  ip,
  status,
}) {
  return (
    <div
      style={{
        display: "flex",
        justifyContent:
          "space-between",
        padding: "18px",
        background: "#0b1320",
        borderRadius: "18px",
        marginBottom: "12px",
      }}
    >
      <span>#{packet}</span>

      <span>{ip}</span>

      <span
        style={{
          color:
            status === "CACHE HIT"
              ? "#00ff99"
              : "#ffcc00",
        }}
      >
        {status}
      </span>
    </div>
  )
}

function LogItem({
  text,
  color,
}) {
  return (
    <div
      style={{
        padding: "16px",
        borderRadius: "16px",
        background: "#0b1320",
        marginBottom: "12px",
        display: "flex",
        alignItems: "center",
        gap: "12px",
      }}
    >
      <div
        style={{
          width: "12px",
          height: "12px",
          borderRadius: "50%",
          background: color,
        }}
      />

      {text}
    </div>
  )
}