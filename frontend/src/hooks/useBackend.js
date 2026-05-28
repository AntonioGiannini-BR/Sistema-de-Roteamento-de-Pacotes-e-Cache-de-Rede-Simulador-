
import { useEffect, useState } from "react";
import { fetchSystemStats } from "../services/api";

export function useBackend() {
  const [backendData, setBackendData] = useState(null);

  useEffect(() => {
    fetchSystemStats().then((data) => {
      if (data) setBackendData(data);
    });
  }, []);

  return backendData;
}
