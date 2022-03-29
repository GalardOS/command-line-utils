all:
	@echo "=== POSIX UTILITIES ==="
	@${MAKE} --no-print-directory -C posix/ -f Makefile

clean:
	@echo "Cleaning posix utilities..."
	cd posix/; ${MAKE} --no-print-directory -f Makefile clean
