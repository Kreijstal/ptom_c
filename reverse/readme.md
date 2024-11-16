# mtok

- The token is located at `0xFB664080`.

- `0xFB65FA80` corresponds to the attribute values of 256 characters.
  - For example, the ASCII code of `#` is `35`. At `[0xFB65FA80 + 35]`, the value is `30`, which represents the attribute of `#`.
    - `30` = `#`
    - `31` = space
    - `27` = `eol` (end-of-line character)?
    - `2` = digit
    - `1` = letter
    - `0` = invalid character
    - `4` = `(` -> `0x34` (decimal `52`)
    - `5` = `)` -> `0x35` (decimal `53`)
    - `25` = `;` -> `0x32` (decimal `50`)

