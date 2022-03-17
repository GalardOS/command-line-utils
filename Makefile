all:
	@echo "Building posix utilities..."
	@${MAKE} --no-print-directory -C posix/ -f Makefile
