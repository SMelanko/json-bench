#pragma once

#include "OpenRtbRef.h"
#include "Types.h"

/**
 * 3.2.3 Object: Banner
 * This object represents the most general type of impression. Although the term “banner” may have very specific meaning
 * in other contexts, here it can be many things including a simple static image, an expandable ad unit, or even
 * in-banner video (refer to the Video object in Section 3.2.4 for the more generalized and full featured video ad units).
 * An array of Banner objects can also appear within the Video to describe optional companion ads defined in the VAST
 * specification.
 * The presence of a Banner as a subordinate of the Imp object indicates that this impression is offered as a banner
 * type impression. At the publisher’s discretion, that same impression may also be offered as video and/or native by
 * also including as Imp subordinates the Video and/or Native objects, respectively. However, any given bid for
 * the impression must conform to one of the offered types.
 */

struct Banner
{
public:
    /// Width of the impression in pixels. If neither wmin nor wmax are specified,
    /// this value is an exact width requirement. Otherwise it is a preferred width.
    Int w;
    /// Height of the impression in pixels. If neither hmin nor hmax are specified,
    /// this value is an exact height requirement. Otherwise it is a preferred height.
    Int h;
    /// Maximum width of the impression in pixels. If included along with a w value
    /// then w should be interpreted as a recommended or preferred width.
    Int wmax;
    /// Maximum height of the impression in pixels. If included along with an h value
    /// then h should be interpreted as a recommended or preferred height.
    Int hmax;
    /// Minimum width of the impression in pixels. If included along with a w value
    /// then w should be interpreted as a recommended or preferred width.
    Int wmin;
    /// Minimum height of the impression in pixels. If included along with an h value
    /// then h should be interpreted as a recommended or preferred height.
    Int hmin;
    /// Unique identifier for this banner object. Recommended when Banner objects are used with a Video object
    /// (Section 3.2.4) to represent an array of companion ads. Values usually start at 1 and increase with each object;
    /// should be unique within an impression.
    Utf8String id;
    /// Blocked banner ad types.
    List<BannerAdType> btype;
    /// Blocked creative attributes.
    List<CreativeAttribute> battr;
    /// Ad position on screen.
    AdPosition pos;
    /// Content MIME types supported. Popular MIME types may include “application/x-shockwave-flash”,
    /// “image/jpg”, and “image/gif”.
    List<MimeType> mimes;
    /// Indicates if the banner is in the top frame as opposed to an iframe, where 0 = no, 1 = yes.
    FramePosition topframe;
    /// Directions in which the banner may expand.
    List<ExpandableDirection> expdir;
    /// List of supported API frameworks for this impression. If an API is not explicitly listed,
    /// it is assumed not to be supported.
    List<ApiFramework> api;
    /// Placeholder for exchange-specific extensions to OpenRTB.
    Json ext;
};
