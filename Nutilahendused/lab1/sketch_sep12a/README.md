# ESP32 MPX5700AP Pressure Sensor

PlatformIO project converted from the original Arduino sketch.

## Hardware

- Sensor: MPX5700AP absolute pressure sensor
- Board: M5Stack AtomS3
- Sensor input: GPIO5
- Serial monitor: COM6 at 115200 baud
- Sensor supply used for conversion: 5.06 V

The project uses PlatformIO board ID `m5stack-atoms3`.

## Commands

```powershell
.\.venv\Scripts\platformio.exe run -d Nutilahendused\sketch_sep12a
.\.venv\Scripts\platformio.exe run -d Nutilahendused\sketch_sep12a -t upload
.\.venv\Scripts\platformio.exe device monitor -d Nutilahendused\sketch_sep12a -p COM6 -b 115200
```

To log serial output to a separate file:

```powershell
.\.venv\Scripts\python.exe Nutilahendused\sketch_sep12a\tools\log_serial.py
```

By default this writes a timestamped file under `Nutilahendused\sketch_sep12a\logs\`. Press `Ctrl+C` to stop logging.

To choose the filename or log for a fixed time:

```powershell
.\.venv\Scripts\python.exe Nutilahendused\sketch_sep12a\tools\log_serial.py --output pressure.log --duration 60
```

At normal room air pressure, `P_abs` should usually be around `101 kPa`, depending on weather and altitude. `P_gauge` should be close to `0 kPa` after startup because the startup sample is used as the local atmospheric reference.

Verified on the attached AtomS3: the sensor reported about `96-97 kPa` absolute and `-0.6` to `0.6 kPa` gauge in room air.
