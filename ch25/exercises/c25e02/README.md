### (a)
`mbcheck` will return `-1`, `\xaa` is not a valid second byte.

### (b)
`mbcheck` will return `-1`, `\x3f` is not a valid second byte.

### (c)
`mbcheck` will return `-1`, no byte after `\xef`.

### (d)
`mbcheck` will return `0`.
