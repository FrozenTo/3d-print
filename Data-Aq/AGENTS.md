# AGENTS.md

## Project overview

This repository contains coursework for robotics-related subjects at the University of Tartu Narva College.

The current project is:

**Data Acquisition — Lab 1: Sensor and automatically controlled compressor**

The goal is to measure the pressure of an MG400 pump system, log the measurements, and automatically control the pump based on measured pressure.

The project combines:

* Dobot MG400 robot
* MG400 pump box
* AtomS3
* Pressure sensor
* Python
* UART / USB serial communication
* MG400 digital outputs
* Data logging and signal analysis

---

## Repository structure

The Data Acquisition Lab 1 files are located in:

```text
data-acquisition/lab1/
```

Expected structure:

```text
data-acquisition/lab1/
├── README.md
├── src/
├── data/
├── notebooks/
└── docs/
```

### `src/`

Source code:

* AtomS3 firmware
* Python serial logger
* MG400 pump control code

### `data/`

Experimental measurement data:

* CSV logs
* sensor tests
* pump ON/OFF measurements
* smart pump box measurements
* robot pickup test measurements

### `notebooks/`

Data analysis:

* FFT
* Welch PSD
* noise analysis
* pressure curves
* plots

### `docs/`

Documentation:

* `sensor_choice.md`
* `bom.md`
* `pump_control.md`
* Falstad diagrams
* draw.io diagrams
* oscilloscope screenshots
* prototype photos

---

## Hardware

Current hardware may include:

* Dobot MG400
* MG400 pump box
* AtomS3
* MPX5700AP pressure sensor
* breadboard
* multimeter
* oscilloscope
* 4 mm pneumatic tubing
* T-connectors
* suction cup
* 24 × 24 mm polycarbonate/glass test piece

Do not assume that additional hardware is available unless it has been documented in the repository.

---

## Software

Main software and tools:

* Python 3
* pyserial
* pandas
* numpy
* scipy
* matplotlib
* Jupyter Lab
* Arduino IDE or PlatformIO
* Git
* GitHub
* Visual Studio Code
* Codex / ChatGPT
* Falstad Circuit Simulator
* draw.io

---

## Measurement system

The intended data flow is approximately:

```text
Pressure sensor
      ↓
   AtomS3
      ↓ UART / USB
    Python
      ↓
 MG400 digital output
      ↓
   Pump box
```

AtomS3 measures pressure and makes the requested pump-control decision.

The computer:

* receives measurements from AtomS3
* logs measurements
* controls the MG400 digital output

---

## Sampling

The target sampling interval is:

```text
10 ms
```

Target sampling frequency:

```text
100 Hz
```

A 10 second measurement should therefore contain approximately:

```text
1000 samples
```

Do not change the sampling frequency without documenting why.

---

## CSV format

The basic measurement CSV should contain at least:

```text
t_ms,adc,p_kpa,pump
```

Additional columns may be added when useful.

Do not rename existing columns without checking dependent analysis scripts.

---

## Serial communication

Example AtomS3 → computer message:

```json
{"t":123456,"adc":2011,"p":-52.3,"mode":"suction","pump":1}
```

Example computer → AtomS3 messages:

```json
{"cmd":"mode","mode":"suction"}
{"cmd":"band","on":-40,"off":-60}
{"cmd":"stop"}
```

Prefer newline-delimited JSON messages.

Keep the protocol simple and human-readable.

---

## Pump safety

The safe state of the system is:

```text
PUMP OFF
```

The pump must switch OFF if:

* serial communication is lost
* no valid AtomS3 message is received for 500 ms
* pressure reading is invalid
* pressure reading is outside the valid range
* the controller enters an error state
* the user sends a stop command

Never change fail-safe behaviour to default to pump ON.

---

## Pump control

Pump control must use hysteresis.

Do not repeatedly switch the pump ON and OFF around one pressure threshold.

Control parameters may include:

* pump ON pressure
* pump OFF pressure
* minimum pump-off time
* maximum pump starts per minute

These values must come from actual measurements.

Do not invent control values.

Final values should be documented in:

```text
docs/pump_control.md
```

---

## Sensor calculations

Sensor conversions must be based on the corresponding sensor datasheet.

For MPX5700AP, document any conversion constants used.

Keep units explicit:

* V
* mV
* Pa
* kPa
* ms
* Hz

Avoid calculations where units are unclear.

---

## Experimental data

Experimental data is important evidence for the laboratory work.

### Never:

* invent measurement values
* replace real measurements with expected values
* silently correct unusual measurements
* delete measurements because they look wrong
* overwrite raw CSV files

If a measurement appears incorrect, keep the original result and document the reason for repeating the experiment.

Prefer creating a new file rather than overwriting raw data.

Example:

```text
smart_box_test_01.csv
smart_box_test_02.csv
```

---

## Documentation rules

Use actual:

* filenames
* measured values
* units
* dates

Do not write placeholder values as if they were measurements.

If a value has not yet been measured, use:

```text
TODO: measure
```

or

```text
Not measured yet
```

instead of guessing.

---

## Development log

Do not remove old development-log entries.

Each work session should add a new entry containing:

```text
Date
People present
What was done
Measured values
Decisions and reasoning
Tasks for next session
```

If an earlier result was wrong, leave it in place and add the correction below it with a new date.

---

## Code style

### Python

Prefer:

* clear function names
* small functions
* type hints where useful
* constants instead of unexplained magic numbers
* comments explaining hardware-specific behaviour

Example:

```python
SERIAL_TIMEOUT_MS = 500
SAMPLE_INTERVAL_MS = 10
```

instead of:

```python
if timer > 500:
```

when the meaning is not obvious.

### AtomS3 / C++

Keep hardware pin definitions and configuration values near the top of the program.

Example:

```cpp
constexpr int PRESSURE_SENSOR_PIN = 1;
constexpr int SAMPLE_INTERVAL_MS = 10;
```

---

## Hardware changes

Do not assume wiring based only on code.

Before suggesting pin changes:

1. check the AtomS3 documentation
2. check the sensor datasheet
3. check the existing wiring documentation

Document any wiring change.

---

## Safety

Important laboratory rules:

* disconnect USB and 5 V before changing sensor wiring
* AtomS3 ADC must not receive more than 3.3 V
* disconnect the 24 V pump-box supply before changing DO wiring
* disable the robot before modifying pump connections
* keep the emergency stop accessible during robot tests
* do not place hands inside the robot workspace while it is enabled
* do not aim a pressurized open hose at people
* do not attach the vacuum suction cup to skin
* no soldering is required in this laboratory

---

## Git

Make small, understandable commits.

Examples:

```text
Add AtomS3 pressure reading
Add 100 Hz serial logger
Add smart box pressure measurements
Add pump hysteresis control
Add FFT analysis notebook
```

Do not commit generated temporary files or large unnecessary files.

Raw experimental data that is part of the laboratory evidence should be committed.

Final Lab 1 tag:

```text
data-acquisition-lab1
```

---

## Before making major changes

Before modifying working code:

1. understand what the existing code does
2. preserve currently working functionality
3. avoid unrelated refactoring
4. make the smallest change needed
5. test the change
6. document behaviour that changed

For hardware-control code, prefer simple and predictable behaviour over clever abstractions.

---

## AI agent rules

When assisting with this repository:

* do not fabricate experimental results
* do not claim hardware was tested unless a human actually tested it
* clearly distinguish calculated values from measured values
* preserve raw experimental files
* preserve development history
* explain important engineering decisions
* prioritize hardware safety
* ask for measured values when calculations depend on measurements
* leave TODO markers where real-world testing is still required
