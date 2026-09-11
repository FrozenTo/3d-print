# AGENTS.md

## Project overview

This repository contains work for the robotics and 3D printing courses.

The team is developing a system where an MG400 robot draws a character
displayed by an ESP32.

## Repository structure

- `3d-print/lab1/` — 3D Printing Lab 1
- `3d-print/lab1/README.md` — lab documentation and development log
- CAD source files, STL files and 3MF files must be kept in the lab folder.

## File rules

- Do not delete old prototype versions.
- Create a new file for every significant prototype iteration.
- Use descriptive filenames such as:
  - `cube_gap_0.25mm.stl`
  - `flex_test_v01.stl`
  - `pen_holder_v01.stl`
  - `pen_holder_v02.stl`

## Documentation

When changing a prototype, document:
- what was changed;
- why it was changed;
- measured values and units;
- test result.

Do not replace previous development log entries.
Add new entries below the old ones.

## 3D printing

- CAD software: Fusion 360
- Slicer: PrusaSlicer
- Material: PLA unless documented otherwise
- Printer settings and measurements should be recorded in the lab README.

## Safety

- Do not suggest running the MG400 at high speed for the first test.
- Initial robot tests should use low speed.
- Emergency stop must be accessible.