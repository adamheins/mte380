# MTE 380
Software code for the MTE 380 Robot Project.

## Contributing
To contribute to the repository, do the following:

1. Clone the repository.
2. Make a new branch for your work. A descriptive branch name is preferred.
3. Push the branch containing your changes.
4. Submit a Pull Request, and get someone to review your changes. If everything
   looks good, merge it!

Avoid circumventing the above procedure and pushing directly to master. This
has a tendency to fuck things up.

## Environment
For this project, we are using an Arduino Mega with an Atmega 2560. The Arduino
IDE can be downloaded [here](https://www.arduino.cc/en/Main/Software).

The code is not currently written in an Arduino-ish way. So we've got a good
old Makefile.  Run `make test` to compile and run the unit tests. This creates
an executable binary in the `bin` directory, which runs the unit tests. Run
`make clean` to remove the generated binary files.

## Tests
Unit tests go in the `test` directory. We're using a C unit testing framework
called `clar`. The information and code for it can be found
[here](https://github.com/vmg/clar).

## Code Style
This isn't a huge software project so we needn't be too stringent here, but
let's not make a mess. Keep lines to a length of 80 characters. When in doubt,
follow the
[Google Style Guide](https://google.github.io/styleguide/cppguide.html).
