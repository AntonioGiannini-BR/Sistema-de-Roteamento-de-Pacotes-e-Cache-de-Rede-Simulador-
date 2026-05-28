
export async function fetchSystemStats() {
  try {
    const response = await fetch("http://localhost:8888");
    return await response.json();
  } catch (error) {
    console.log("Backend offline");
    return null;
  }
}
