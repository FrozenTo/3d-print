# AGENTS.md

## Project overview

This repository contains coursework for multiple connected robotics subjects.

The subjects are related and may share hardware, measurements, code and documentation.

For **Nutikad Lahendused — Labor 1**, the final system is:

```text
AtomS3
   ↓ WiFi / network message
Laptop / station
   ↓ Ethernet / Dobot TCP/IP
MG400
   ↓
Pen holder / vacuum tooling
```

The final goal of this lab is:

> A letter is selected and sent from the AtomS3, received by the laptop, converted into robot movements, and drawn by the MG400.

The same project also connects to:

- **Andmehõive** — AtomS3, sensors, button input and communication.
- **3D printimine ja CAD** — physical pen/tool holder for the MG400.
- **Nutikad Lahendused** — integration between AtomS3, laptop and MG400.

Do not treat these parts as completely independent if a change affects their shared interfaces.

---

# General rules

## 1. Do not invent measurements

Never invent:

- robot coordinates;
- IP addresses that have not been confirmed;
- measured voltage;
- timing results;
- latency;
- upload duration;
- DO line assignments;
- dimensions;
- test results;
- success rates.

If a value must be measured physically, mark it clearly as:

```text
TODO: measure
```

or:

```text
NOT MEASURED YET
```

A real unknown value is better than an invented value.

---

## 2. Preserve previous measurements

This project uses a development-log style where old measurements are not silently replaced.

If a previous value was found to be wrong:

- keep the old result where appropriate;
- add the corrected result;
- include the date;
- explain why it changed.

Example:

```md
12.09.2026:
Initial assumption: DO2 = vacuum.

15.09.2026:
Measured with a multimeter.
DO2 actually controls blow.
Configuration updated accordingly.
```

Do not rewrite history to make the project appear cleaner.

---

## 3. Prefer clear and simple solutions

This is a university robotics laboratory project.

Prefer:

- understandable code;
- small modules;
- explicit variables;
- readable configuration files;
- simple HTTP APIs;
- documented constants.

Avoid unnecessary:

- frameworks;
- abstractions;
- design patterns;
- dependency-heavy solutions;
- premature optimisation.

A team member should be able to understand the code later without needing the original author.

---

# Repository structure

The Nutikad Lahendused Lab 1 files should follow approximately this structure:

```text
smart-solutions/
└── lab1/
    ├── README.md
    ├── CHECKLIST.md
    ├── src/
    ├── firmware/
    ├── data/
    │   └── positions.json
    └── docs/
        ├── bom.md
        ├── atom_page.md
        ├── letter_channel.md
        ├── letters.md
        ├── pick_test.csv
        ├── latency.csv
        └── ...
```

Do not move files unnecessarily.

If a new file is introduced, place it according to its purpose:

- Python integration code → `src/`
- AtomS3 PlatformIO code → `firmware/`
- machine-readable data → `data/`
- measurements and documentation → `docs/`

---

# README.md

`README.md` is the main laboratory document.

When editing it:

- preserve the laboratory requirements;
- fill in measured results as work progresses;
- use real file names;
- include units;
- include exact values where known;
- clearly mark unfinished work;
- do not delete previous incorrect measurements if the laboratory requires them to remain documented.

The reader should be able to understand the project even if they were not present during the laboratory session.

---

# CHECKLIST.md

`CHECKLIST.md` tracks implementation progress.

When completing a task:

```md
- [ ] Task
```

may become:

```md
- [x] Task
```

Only mark something complete if it was actually completed or tested.

Do not mark tasks complete simply because code for them exists.

For hardware-related tasks, completion normally means it was tested on the real hardware.

---

# Development log

Add one entry for each real work session.

Use this format:

```md
## DD.MM.YY — participants

### Tegime
- What was done.

### Juhtus
- Measurements and observations.

### Otsustasime, ja miks
- Decisions and their reasoning.

### Lahti järgmiseks korraks
- What remains unfinished.
```

Do not fabricate development-log entries.

Do not add work that did not actually happen.

---

# MG400

## Network configuration

Expected laboratory configuration:

```text
MG400:
192.168.1.6

Laptop Ethernet:
192.168.1.50

Subnet mask:
255.255.255.0

Gateway:
empty
```

These values are laboratory assumptions and must still be verified on the real system.

If the actual configuration differs, document the real values.

---

## Dobot TCP/IP ports

The project uses the Dobot TCP/IP API.

Expected ports:

```text
29999 — dashboard / robot commands
30003 — movement commands
30004 — feedback
```

Common commands may include:

```text
EnableRobot
ClearError
GetPose
DO
MovL
ServoP
```

Do not change protocol assumptions without checking the MG400 base package or Dobot documentation.

---

# Robot safety

Safety takes priority over convenience.

## Never automatically run physical movement

An AI agent may:

- write movement code;
- generate trajectories;
- validate syntax;
- calculate coordinates from confirmed values.

An AI agent must not assume that generated robot code is safe to execute.

Before a new movement sequence is physically tested:

1. Set robot speed to approximately 20%.
2. Keep the emergency stop accessible.
3. Ensure people are outside the robot work area.
4. Announce that the robot is about to move.
5. Run the first trajectory above the work surface.
6. Keep the tool approximately 20 mm above the surface for the first dry run.
7. Only then test the real working Z height.

Only one program should send movement commands to the robot at a time.

---

## Z-axis changes

Be especially careful with Z coordinates.

Do not automatically make the robot move lower because a requested value appears reasonable.

When changing Z limits or working Z:

- preserve configured safety limits unless the user explicitly changes them;
- distinguish software limits from actual safe physical limits;
- perform the first run above the surface.

---

# Vacuum pump

The MG400 pump box uses digital outputs.

Initial package assumption:

```text
DO2 = suction
DO1 = blow
```

This must be verified physically.

Do not treat these assignments as confirmed until they have been checked using:

- the pump documentation;
- wiring;
- a multimeter;
- or a controlled hardware test.

If measurements contradict the software assumption, update the configuration and document the result.

The pump system may use 24 V.

Do not recommend changing wiring while powered.

---

# Robot positions

Robot positions are stored in:

```text
data/positions.json
```

Required named positions include:

```text
above_source
source
above_finished
finished
```

Positions must come from the real robot.

Never generate plausible coordinates and save them as if they were measured.

A position may contain values such as:

```json
{
  "x": 0,
  "y": 0,
  "z": 0,
  "r": 0
}
```

but placeholder values must be clearly labelled as placeholders.

---

# Pick-and-place testing

Results belong in:

```text
docs/pick_test.csv
```

The laboratory requires ten consecutive tests.

Record actual results.

Suggested fields:

```csv
test,picked,placed,note
1,yes,yes,OK
2,yes,no,object shifted
```

Do not generate successful test data automatically.

---

# AtomS3 firmware

AtomS3 firmware belongs in:

```text
firmware/
```

The expected environment is:

- VS Code
- PlatformIO
- board: `m5stack-atoms3`
- M5Unified
- serial baud rate: `115200`

The AtomS3 acts as a WiFi access point and HTTP server.

The expected default AP address is:

```text
192.168.4.1
```

Treat it as an expected value until verified.

---

# AtomS3 web interface

The AtomS3 should use one main web interface.

Do not create a separate web page for every future device.

The same interface should grow to support features such as:

- WiFi configuration;
- station address;
- display test;
- pressure sensor;
- UART;
- valve;
- LED;
- future hardware.

Document the current interface in:

```text
docs/atom_page.md
```

---

# Captive portal

The final behaviour should be:

```text
Phone joins AtomS3 WiFi
        ↓
Phone performs connectivity check
        ↓
Atom responds
        ↓
Phone opens the Atom web page automatically
```

Captive portal implementation may use an ESP32 DNS server that resolves requests to the Atom's own address.

Do not hard-code undocumented Android or iOS behaviour without recording what was actually observed.

When testing, record the connectivity-check URLs requested by the phone.

---

# Letter communication

The communication contract between AtomS3 and the laptop belongs in:

```text
docs/letter_channel.md
```

The basic message format is:

```json
{"letter":"A"}
```

The team must explicitly agree on how the message travels.

Possible designs include:

### Polling

```text
Laptop → Atom:
Any new letter?

Atom → Laptop:
{"letter":"A"}
```

### Push

```text
Atom → Laptop:
HTTP request
{"letter":"A"}
```

Do not implement incompatible solutions independently on the Atom and laptop sides.

Document before finalising:

- who initiates the connection;
- IP address;
- port;
- endpoint;
- JSON format;
- expected response;
- error behaviour.

---

# Station application

The laptop acts as the station connecting the AtomS3 and MG400.

Station code belongs in:

```text
src/
```

Its responsibilities include:

1. receive a letter;
2. timestamp the received message;
3. validate the message;
4. verify robot state;
5. find the requested letter trajectory;
6. move to the first point with the pen raised;
7. lower the pen;
8. draw the required line segments;
9. raise the pen between disconnected strokes;
10. return a useful status/error message.

Do not move the robot if it is not enabled or ready.

---

# Letter trajectories

Letter definitions should be documented in:

```text
docs/letters.md
```

At least three letters are required.

A letter should be represented as coordinates or strokes rather than large amounts of hard-coded movement logic.

Prefer a structure such as:

```python
LETTERS = {
    "A": [
        # stroke 1
        [(0, 0), (10, 20), (20, 0)],

        # stroke 2
        [(5, 10), (15, 10)],
    ]
}
```

The exact representation may differ, but it should clearly represent:

- separate strokes;
- pen-up movement;
- pen-down movement;
- relative or absolute coordinates.

Document which coordinate system is used.

---

# Drawing safety

Every new letter trajectory should first be tested:

```text
20% speed
pen approximately 20 mm above paper
```

Only after the dry run succeeds should the working Z be used.

When changing from a taped marker to the 3D-printed holder, recalibrate the working Z.

Do not assume the previous Z remains correct.

---

# Latency measurements

Latency data belongs in:

```text
docs/latency.csv
```

The laboratory requires 30 button-press measurements.

Each measurement should contain three timestamps:

```text
Atom sent
Station received
Station sent first robot command
```

Calculate:

```text
Atom → station:
- average
- maximum

Station → robot:
- average
- maximum
```

Do not generate synthetic latency data.

Code may calculate statistics from recorded data.

---

# BOM

The bill of materials belongs in:

```text
docs/bom.md
```

Each item should include a reason.

Example:

```md
| Component | Quantity | Reason |
|---|---:|---|
| USB-C → Ethernet adapter | 1 | Required to connect a laptop without Ethernet to the MG400 |
```

Only include components relevant to the actual planned system.

---

# Documentation style

Documentation may be written in Estonian.

Prefer:

- clear B2–C1 level language;
- short technical sentences;
- consistent terminology;
- exact names of files;
- exact commands;
- real values;
- units with measurements.

Avoid unnecessary academic filler.

The documentation should explain what was actually done rather than trying to sound complicated.

---

# Code style

## Python

Prefer:

- Python 3.11+
- `pathlib` for file paths
- type hints where useful
- descriptive function names
- constants for configuration values
- small functions
- clear exception handling
- logging instead of excessive `print()` statements for application events

Example:

```python
ROBOT_IP = "192.168.1.6"
DASHBOARD_PORT = 29999
MOVE_PORT = 30003
```

Do not scatter the same configuration value throughout several files.

---

## Configuration

Hardware-specific values should be configurable where practical.

Examples:

- robot IP;
- station IP;
- Atom address;
- robot speed;
- pump DO channels;
- drawing height;
- travel height.

Avoid deeply embedding laboratory-specific values in unrelated logic.

---

# Error handling

Hardware errors should be visible and understandable.

Prefer messages such as:

```text
Robot is not enabled.
```

```text
Could not connect to MG400 at 192.168.1.6:29999.
```

```text
Unknown letter: Q
```

```text
Atom message does not contain "letter".
```

Avoid silently ignoring failures.

---

# Testing

Software-only functions should be testable without moving the real robot where possible.

Good candidates include:

- JSON parsing;
- letter validation;
- trajectory generation;
- coordinate transforms;
- CSV statistics;
- configuration loading.

Separate pure calculations from physical robot commands where practical.

Example:

```text
letter_to_points("A")
```

should be testable without connecting to the MG400.

---

# Hardware tests

Never claim a hardware feature works until it has been tested physically.

Examples:

```text
Code implemented: YES
Tested on real MG400: NO
```

is valid documentation.

Do not change it to:

```text
Working: YES
```

until it has actually been verified.

---

# External repositories

This project may use:

```text
KKallas/mg400-base
Dobot-Arm/TCP-IP-Protocol
Dobot-Arm/TCP-IP-4Axis-Python
KKallas/ESP32-Image-Server
M5Stack/M5Unified
```

When modifying code originating from another repository:

- keep attribution where appropriate;
- document important changes;
- do not copy large sections unnecessarily;
- prefer a focused modification;
- consider submitting fixes upstream when required by the assignment.

---

# Git workflow

Before committing:

1. Review changed files.
2. Remove temporary debug output where appropriate.
3. Do not commit secrets.
4. Do not commit real WiFi passwords.
5. Confirm generated files belong in Git.
6. Update documentation when behaviour changed.

Use meaningful commit messages.

Examples:

```text
add mg400 position storage
```

```text
implement atom captive portal
```

```text
add letter A trajectory
```

```text
document pump DO measurements
```

Avoid meaningless messages such as:

```text
stuff
```

```text
update
```

```text
test
```

unless the context genuinely makes them useful.

---

# Secrets and credentials

Never commit:

- private WiFi passwords;
- personal access tokens;
- API keys;
- SSH private keys;
- account passwords.

Use placeholders in documentation:

```text
WIFI_PASSWORD=<configured locally>
```

If credentials are accidentally committed, notify the user instead of merely deleting them from the newest file version.

---

# Final laboratory requirements

Before considering Lab 1 complete, verify that the project contains evidence for:

- MG400 reachable from the laptop;
- `mg400 status` working;
- MG400 web interface working;
- suction working;
- blow working;
- four saved robot positions;
- ten pick-and-place tests;
- AtomS3 firmware installed;
- AtomS3 WiFi access point working;
- captive portal working;
- image upload to Atom display working;
- settings/test area on the Atom page;
- documented Atom ↔ station communication;
- at least three letter trajectories;
- Atom-selected letter reaching the station;
- MG400 drawing the selected letter;
- thirty latency measurements;
- BOM;
- development log;
- draw.io system diagram;
- updated documentation.

Final Git tag:

```text
smart-solutions-lab1
```

---

# Instructions for AI coding agents

When asked to implement a change:

1. Inspect the relevant existing files first.
2. Reuse the current project structure.
3. Do not rewrite unrelated working code.
4. Keep changes focused on the requested task.
5. Explain important assumptions in comments or documentation.
6. Do not invent hardware measurements.
7. Do not automatically execute robot movement.
8. Clearly distinguish:
   - implemented;
   - simulated/tested in software;
   - tested on real hardware.
9. Update relevant documentation when behaviour or interfaces change.
10. Preserve compatibility with the other connected laboratory subjects whenever possible.

When uncertain about a physical hardware value, prefer a configurable placeholder and ask for or wait for the real measurement rather than guessing.