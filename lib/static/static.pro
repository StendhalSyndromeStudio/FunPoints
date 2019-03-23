TEMPLATE = subdirs

SUBDIRS += \
    baseTypes \
    baseTypesImpl


baseTypesImpl.depends = baseTypes
