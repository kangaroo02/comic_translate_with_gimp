/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimpguides_pdb.c
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#include "config.h"

#include "gimp.h"


/**
 * SECTION: gimpguides
 * @title: gimpguides
 * @short_description: Functions for manipulating guides.
 *
 * Functions for manipulating guides.
 **/


/**
 * gimp_image_add_hguide:
 * @image_ID: The image.
 * @yposition: The guide's y-offset from top of image.
 *
 * Add a horizontal guide to an image.
 *
 * This procedure adds a horizontal guide to an image. It takes the
 * input image and the y-position of the new guide as parameters. It
 * returns the guide ID of the new guide.
 *
 * Returns: The new guide.
 **/
gint32
gimp_image_add_hguide (gint32 image_ID,
                       gint   yposition)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint32 guide_ID = -1;

  return_vals = gimp_run_procedure ("gimp-image-add-hguide",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, yposition,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    guide_ID = return_vals[1].data.d_int32;

  gimp_destroy_params (return_vals, nreturn_vals);

  return guide_ID;
}

/**
 * gimp_image_add_vguide:
 * @image_ID: The image.
 * @xposition: The guide's x-offset from left of image.
 *
 * Add a vertical guide to an image.
 *
 * This procedure adds a vertical guide to an image. It takes the input
 * image and the x-position of the new guide as parameters. It returns
 * the guide ID of the new guide.
 *
 * Returns: The new guide.
 **/
gint32
gimp_image_add_vguide (gint32 image_ID,
                       gint   xposition)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint32 guide_ID = -1;

  return_vals = gimp_run_procedure ("gimp-image-add-vguide",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, xposition,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    guide_ID = return_vals[1].data.d_int32;

  gimp_destroy_params (return_vals, nreturn_vals);

  return guide_ID;
}

/**
 * gimp_image_delete_guide:
 * @image_ID: The image.
 * @guide_ID: The ID of the guide to be removed.
 *
 * Deletes a guide from an image.
 *
 * This procedure takes an image and a guide ID as input and removes
 * the specified guide from the specified image.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_image_delete_guide (gint32 image_ID,
                         gint32 guide_ID)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-image-delete-guide",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, guide_ID,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_image_find_next_guide:
 * @image_ID: The image.
 * @guide_ID: The ID of the current guide (0 if first invocation).
 *
 * Find next guide on an image.
 *
 * This procedure takes an image and a guide ID as input and finds the
 * guide ID of the successor of the given guide ID in the image's guide
 * list. If the supplied guide ID is 0, the procedure will return the
 * first Guide. The procedure will return 0 if given the final guide ID
 * as an argument or the image has no guides.
 *
 * Returns: The next guide's ID.
 **/
gint32
gimp_image_find_next_guide (gint32 image_ID,
                            gint32 guide_ID)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint32 next_guide_ID = -1;

  return_vals = gimp_run_procedure ("gimp-image-find-next-guide",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, guide_ID,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    next_guide_ID = return_vals[1].data.d_int32;

  gimp_destroy_params (return_vals, nreturn_vals);

  return next_guide_ID;
}

/**
 * gimp_image_get_guide_orientation:
 * @image_ID: The image.
 * @guide_ID: The guide.
 *
 * Get orientation of a guide on an image.
 *
 * This procedure takes an image and a guide ID as input and returns
 * the orientations of the guide.
 *
 * Returns: The guide's orientation.
 **/
GimpOrientationType
gimp_image_get_guide_orientation (gint32 image_ID,
                                  gint32 guide_ID)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  GimpOrientationType orientation = GIMP_ORIENTATION_UNKNOWN;

  return_vals = gimp_run_procedure ("gimp-image-get-guide-orientation",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, guide_ID,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    orientation = return_vals[1].data.d_int32;

  gimp_destroy_params (return_vals, nreturn_vals);

  return orientation;
}

/**
 * gimp_image_get_guide_position:
 * @image_ID: The image.
 * @guide_ID: The guide.
 *
 * Get position of a guide on an image.
 *
 * This procedure takes an image and a guide ID as input and returns
 * the position of the guide relative to the top or left of the image.
 *
 * Returns: The guide's position relative to top or left of image.
 **/
gint
gimp_image_get_guide_position (gint32 image_ID,
                               gint32 guide_ID)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint position = -1;

  return_vals = gimp_run_procedure ("gimp-image-get-guide-position",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_INT32, guide_ID,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    position = return_vals[1].data.d_int32;

  gimp_destroy_params (return_vals, nreturn_vals);

  return position;
}
