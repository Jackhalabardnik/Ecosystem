.PHONY: clean All

All:
	@echo "----------Building project:[ Tests - Release ]----------"
	@cd "Tests" && "$(MAKE)" -f  "Tests.mk"
clean:
	@echo "----------Cleaning project:[ Tests - Release ]----------"
	@cd "Tests" && "$(MAKE)" -f  "Tests.mk" clean
