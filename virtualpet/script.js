const petImage = document.getElementById("pet-image");
const idleBtn = document.getElementById("idle-btn");
const layBtn = document.getElementById("lay-btn");
const eatBtn = document.getElementById("eat-btn");
const playBtn = document.getElementById("play-btn");

let hunger = 50;
let happiness = 50;
let energy = 100;
let bounceInterval;
let playInterval;
let layInterval;
let continuousDrainInterval;
let continuousHappinessInterval;
let isPlaying = false;
let currentAction = "idle";

idleBtn.addEventListener("click", () => changeImage("pet.png"));
layBtn.addEventListener("click", () => {
    isPlaying = false;
    clearInterval(continuousDrainInterval);
    clearInterval(continuousHappinessInterval);
    layDown();
});
eatBtn.addEventListener("click", () => {
    isPlaying = false;
    clearInterval(continuousDrainInterval);
    clearInterval(continuousHappinessInterval);
    feedPet();
});
playBtn.addEventListener("click", () => {
    if (!isPlaying) {
        startPlay();
    }
});

function changeImage(imagePath) {
    if (hunger > 0 && happiness > 0) {
        petImage.src = imagePath;
    }
    resetAnimation();
}

function feedPet() {
    if (hunger < 90) {
        hunger += 10;
    }
    updateStatus();
    changeImage("peteating.png");
    resetAnimation();
}

function layDown() {
    if (energy < 90) {
        energy += 10;
    }
    updateStatus();
    changeImage("petlayingdown.png");
    resetAnimation();

    clearInterval(layInterval);
    layInterval = setInterval(() => {
        if (energy < 100) {
            energy += 1;
            updateStatus();
        }
    }, 1000);
}

function startPlay() {
    if (energy >= 10) {
        if (happiness < 90) {
            happiness += 10;
        }
        energy -= 10;
        updateStatus();
        toggleBounce();

        isPlaying = true;

        playInterval = setInterval(() => {
            if (energy > 0) {
                energy -= 1;
            } else {
                clearInterval(playInterval);
                clearInterval(continuousDrainInterval);
                clearInterval(continuousHappinessInterval);
                resetAnimation();
                isPlaying = false;
            }
            updateStatus();
        }, 1000);

        continuousDrainInterval = setInterval(() => {
            if (energy > 0) {
                energy -= 0.5;
            }
            updateStatus();
        }, 200);

        continuousHappinessInterval = setInterval(() => {
            if (happiness < 100) {
                happiness += 7; // Increase happiness by 2 each second
            }
            updateStatus();
        }, 1000); // Increase happiness every second
    }
}

function updateStatus() {
    hunger = Math.min(100, Math.max(0, hunger - 0.3));
    happiness = Math.min(100, Math.max(0, happiness - 0.1));
    energy = Math.min(100, Math.max(0, energy));

    const hungerFill = document.getElementById("hunger-fill");
    const happinessFill = document.getElementById("happiness-fill");
    const energyFill = document.getElementById("energy-fill");
    hungerFill.style.width = `${hunger}%`;
    happinessFill.style.width = `${happiness}%`;
    energyFill.style.width = `${energy}%`;

    const updateMeterColor = (meterFill, value) => {
        meterFill.dataset.value = value;
        if (value <= 10) {
            meterFill.style.backgroundColor = "#e74c3c"; // Red
        } else if (value <= 45) {
            meterFill.style.backgroundColor = "#f39c12"; // Yellow
        } else {
            meterFill.style.backgroundColor = "#3498db"; // Blue
        }
    };

    updateMeterColor(hungerFill, hunger);
    updateMeterColor(happinessFill, happiness);
    updateMeterColor(energyFill, energy);

    if (hunger === 0 || happiness === 0) {
        petImage.src = "petangry.png";
    } else if (currentAction !== "idle") {
        petImage.src = "pet.png";
    }

    if (hunger === 0 && happiness === 0) {
        clearInterval(bounceInterval);
    }
}

function toggleBounce() {
    clearInterval(bounceInterval);
    petImage.style.transform = "scale(1)";
    petImage.src = "petplaying.png";
    playAnimation();
    bounceInterval = setInterval(playAnimation, 600);
}

function playAnimation() {
    petImage.style.transform = "scale(1.1)";
    setTimeout(() => {
        petImage.style.transform = "scale(1)";
    }, 300);
}

function resetAnimation() {
    petImage.style.transform = "scale(1)";
    clearInterval(bounceInterval);
    clearInterval(playInterval);
    clearInterval(layInterval);
    clearInterval(continuousDrainInterval);
    clearInterval(continuousHappinessInterval);
}

updateStatus();

setInterval(() => {
    hunger = Math.min(100, Math.max(0, hunger - 0.3));
    happiness = Math.min(100, Math.max(0, happiness - 0.6));
    updateStatus();
}, 1000);
