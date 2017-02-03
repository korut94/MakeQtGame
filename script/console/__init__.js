__setupPackage__('console')

// Wrap the actual QObject console with a JS object. This is temporary, in the
// future versions the QObject `_console`  will export basic but flexible
// methods to format the text in the game's logger and the Object `console`
// will use them throught subprogram (for example: log, error, warning, etc.).
console = _console
// The `print` object now is an alias for `console.log` so to have just one way to
// print text in the environment.
print = console.log
