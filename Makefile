.PHONY: clean All

All:
	@echo "----------Building project:[ Production - Release ]----------"
	@cd "Production" && "$(MAKE)" -f  "Production.mk"
clean:
	@echo "----------Cleaning project:[ Production - Release ]----------"
	@cd "Production" && "$(MAKE)" -f  "Production.mk" clean
