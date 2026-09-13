# Saved MG400 positions

13.09.2026: Copied the saved positions from
`../../../Data-Aq/Mg400/mg400-base/locations.json` to
`../data/positions.json`. All four poses match the screenshot supplied by the
user. X, Y and Z are in mm; R is in degrees. The first two labels were normalized
from `AboveSource` and `Source` to `above_source` and `source`.

The file retains the MG400 web application's ten-slot JSON format, including
the six unset slots. This is a snapshot: later changes in the web application
do not update this copy unless the server uses this file.

By default, `mg400 serve` saves `locations.json` in the directory from which
it was started. Its `--locations` option selects another file. From the
repository root, use `mg400 serve --locations Nutilahendused/lab1/data/positions.json`
to select the lab copy, retaining any other setup-specific launch options.

The JSON was checked locally. Loading these positions in the running web
application and testing robot movement remain unverified in this session.
