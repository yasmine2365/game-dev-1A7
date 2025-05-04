🎮 SDL 2D Game Project
Overview
This project is a 2D platformer built using SDL (Simple DirectMedia Layer). The game features:

A main character (player) with animated movements

AI-controlled enemies with pursuit behavior

Side-scrolling environments

A quiz-based interaction module

A minimap with real-time position tracking

A start menu and scoreboard system

Time tracking and player name input at game start

🕹️ Features
👤 Player System
Handles player animation, jumping, movement, and collision.

Keeps track of life and game state.

👾 Enemies
Enemies detect player position and follow based on simple AI.

Health and damage logic included.

📜 Menu System
Interactive start and pause menus.

Options to view scoreboards, credits, or start game.

Uses SDL_Mixer for background audio.

🌍 Scrolling Background
Camera follows player through large level.

Smooth parallax scrolling with collision detection.

🧭 Minimap
Displays a scaled-down view of the level.

Real-time tracking of player position.

Includes game timer and name input screen.

❓ Quiz Mechanism
Quiz triggers through interaction.

Supports multiple questions and tracks answers.

🕒 Timer & Score
In-game timer displays MM:SS format.

Player name and final score are saved in ./score/score.txt.
