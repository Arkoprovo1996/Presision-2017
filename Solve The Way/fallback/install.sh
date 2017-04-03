gcc -o solveTheWay solveTheWay.c

if [ ! -d ~/.local/bin ]; then
	mkdir ~/.local/bin
	echo 'export PATH=\$PATH:\~/.local/bin/' >> ~/.bashrc
fi


mv solveTheWay Paths Positions ~/.local/bin/
