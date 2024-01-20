.PHONY: clean All

All:
	@echo "----------Building project:[ RPG1 - Debug ]----------"
	@"$(MAKE)" -f  "RPG1.mk"
clean:
	@echo "----------Cleaning project:[ RPG1 - Debug ]----------"
	@"$(MAKE)" -f  "RPG1.mk" clean
