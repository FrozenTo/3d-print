# RoboticsLesson tools (Windows)

Run commands from the repository root in PowerShell.

## Python, analysis, and MG400

```powershell
git submodule update --init --recursive
py -3.12 -m venv .venv
.\.venv\Scripts\python.exe -m pip install -r requirements.txt
```

For the exact Python dependency versions captured during this setup, use
`-r requirements-lock.txt -r requirements.txt` in the install command.

The root `.venv` provides the lab packages and the editable MG400 package.
Select `.venv\Scripts\python.exe` as the interpreter and notebook kernel in VS Code.
Commands work without activating the environment or changing execution policy:

```powershell
.\.venv\Scripts\jupyter.exe lab
.\.venv\Scripts\python.exe -m serial.tools.list_ports
.\.venv\Scripts\mg400.exe --help
.\.venv\Scripts\pio.exe --help
```

## AtomS3 firmware

PlatformIO CLI manages the ESP32 compiler, Arduino framework, and libraries.
An AtomS3 firmware project's `platformio.ini` can use:

```ini
[env:atoms3]
platform = espressif32@7.1.3
board = m5stack-atoms3
framework = arduino
lib_deps =
    m5stack/M5Unified@0.2.21
    m5stack/M5GFX@0.2.28
```

Build an existing firmware project with:

```powershell
.\.venv\Scripts\pio.exe run --project-dir PATH_TO_FIRMWARE
```

This builds only; uploading requires a separate explicit upload command.
Board reference: https://docs.platformio.org/en/latest/boards/espressif32/m5stack-atoms3.html

Verified on 2026-09-12 with a compile-only test calling `M5.begin()` and
`M5.update()`. Firmware built successfully; no hardware was flashed or tested.
M5Unified supports AtomS3: https://github.com/m5stack/M5Unified

## CAD, slicing, and diagrams

- Autodesk Fusion and PrusaSlicer are already installed on this computer.
- DobotStudio Pro is already installed.
- draw.io desktop was installed using `winget install --id JGraph.Draw --exact --source winget --silent`.
- Falstad runs in the browser: https://www.falstad.com/circuit/circuitjs.html

PrusaSlicer command-line help on this computer:

```powershell
& 'C:\Program Files\Prusa3D\PrusaSlicer\prusa-slicer-console.exe' --help
```

draw.io is installed at `%LOCALAPPDATA%\Programs\draw.io\draw.io.exe`.

Fusion may require signing in with the appropriate Autodesk account; installation does not verify license activation.
