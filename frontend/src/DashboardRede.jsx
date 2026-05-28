export default function DashboardRede() {
  const stats = {
    packetsQueue: 5,
    processed: 12,
    collisions: 2,
    cacheHits: 8,
    cacheMiss: 4,
    priorityPackets: 6,
  };

  const queue = [
    { id: 201, type: 'VOZ/VIDEO', priority: 'ALTA' },
    { id: 202, type: 'STREAMING', priority: 'ALTA' },
    { id: 203, type: 'DOWNLOAD', priority: 'NORMAL' },
  ];

  return (
    <div className="min-h-screen bg-black text-cyan-300 p-8 font-mono">
      <h1 className="text-5xl font-bold mb-8">
        NETWORK ROUTING SYSTEM
      </h1>

      <div className="grid grid-cols-3 gap-6 mb-8">
        <Card title="Pacotes na Fila" value={stats.packetsQueue} />
        <Card title="Processados" value={stats.processed} />
        <Card title="Colisões" value={stats.collisions} />
      </div>

      <div className="rounded-3xl border border-cyan-500 p-6">
        <h2 className="text-2xl mb-4">
          FILA DE PRIORIDADE
        </h2>

        {queue.map((packet) => (
          <div
            key={packet.id}
            className="p-4 rounded-xl border border-cyan-700 mb-4"
          >
            <p>Pacote #{packet.id}</p>
            <p>{packet.type}</p>
            <p>{packet.priority}</p>
          </div>
        ))}
      </div>
    </div>
  );
}

function Card({ title, value }) {
  return (
    <div className="rounded-3xl border border-cyan-500 p-6">
      <p>{title}</p>
      <h2 className="text-5xl font-bold">
        {value}
      </h2>
    </div>
  );
}
