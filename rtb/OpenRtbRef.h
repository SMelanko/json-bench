#pragma once

/**
 * 5.2 Banner Ad Types
 * The following table indicates the types of ads that can be accepted by the exchange unless restricted
 * by publisher site settings.
 */

enum class BannerAdType
{
    /// Not explicitly specified.
    NONE = -1,
    /// XHTML Text Ad (usually mobile).
    XHTML_TEXT = 1,
    /// XHTML Banner Ad (usually mobile).
    XHTML_BANNER = 2,
    /// JavaScript Ad; must be valid XHTML (i.e., Script Tags Included).
    JAVASCRIPT = 3,
    /// Iframe.
    IFRAME = 4
};

/**
 * 5.3 Creative Attributes
 * The following table specifies a standard list of creative attributes that can describe an ad being served
 * or serve as restrictions of thereof.
 */


