/* gimpversion.h
 *
 * This is a generated file.  Please modify 'configure.ac'
 */

#if !defined (__GIMP_BASE_H_INSIDE__) && !defined (GIMP_BASE_COMPILATION)
#error "Only <libgimpbase/gimpbase.h> can be included directly."
#endif

#ifndef __GIMP_VERSION_H__
#define __GIMP_VERSION_H__

G_BEGIN_DECLS


/**
 * SECTION: gimpversion
 * @title: gimpversion
 * @short_description: Macros and constants useful for determining
 *                     GIMP's version number and capabilities.
 *
 * Macros and constants useful for determining GIMP's version number and
 * capabilities.
 **/

/**
 * GIMP_MAJOR_VERSION:
 *
 * The major GIMP version number.
 **/
#define GIMP_MAJOR_VERSION                              (2)

/**
 * GIMP_MINOR_VERSION:
 *
 * The minor GIMP version number.
 **/
#define GIMP_MINOR_VERSION                              (8)

/**
 * GIMP_MICRO_VERSION:
 *
 * The micro GIMP version number.
 **/
#define GIMP_MICRO_VERSION                              (20)

/**
 * GIMP_VERSION:
 *
 * The GIMP version as a string.
 **/
#define GIMP_VERSION                                    "2.8.20"

/**
 * GIMP_API_VERSION:
 *
 * Since: GIMP 2.2
 **/
#define GIMP_API_VERSION                                "2.0"

#define GIMP_CHECK_VERSION(major, minor, micro) \
    (GIMP_MAJOR_VERSION > (major) || \
     (GIMP_MAJOR_VERSION == (major) && GIMP_MINOR_VERSION > (minor)) || \
     (GIMP_MAJOR_VERSION == (major) && GIMP_MINOR_VERSION == (minor) && \
      GIMP_MICRO_VERSION >= (micro)))


G_END_DECLS

#endif /* __GIMP_VERSION_H__ */
