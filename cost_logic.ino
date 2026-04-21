// --- COST CALCULATION LOGIC ---
extern float totalVolumeML; // Pulls the volume from the flow sensor
float totalCostKSh = 0.0;

void calculateCost() {
  // Calculates exactly 12 KSh for every 80 ml dispensed
  totalCostKSh = (totalVolumeML / 80.0) * 12.0;
}
