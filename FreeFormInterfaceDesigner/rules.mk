MODULE := freeform_designer

freeform_designer_TARGET := freeform-interface-designer
freeform_designer_CXXFLAGS :=
freeform_designer_LIBS := -lglut -lfreeimage -lGLEW -lGL -lGLU $(scv_TARGET)

include common-rules.mk
