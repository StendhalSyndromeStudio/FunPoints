TEMPLATE = subdirs

SUBDIRS += \
    baseTypes \
    baseTypesImpl \
    MarkerModel


baseTypesImpl.depends = baseTypes
