//
// OWLNext
//
/// \file version.h
/// Library version and build information header (template).
///
/// If you see $WC tags in this file, then this is the template for automatic generation of the
/// public header "owl/version.h", and the path of the file should be "source/owlcore/version.h". 
/// The fields will be substituted by real build data by SubWCRev, or similar tools, during the 
/// build process. If you don't see $WC tags, then this file is the final result, and the path of
/// the file should be "include/owl/version.h".
///
/// NOTE! Do not edit this file if it is located at "include/owl". Edit the source file located 
/// at "source/owlcore instead.
// 
// Copyright � 1991, 1996 by Borland International, All Rights Reserved
// Copyright � 1998-2000 by Yura Bidus
// See OWLNext for license information (http://owlnext.sourceforge.net).

#if !defined(OWL_VERSION_H)
#define OWL_VERSION_H

// Flags
//
#define OWL_PRERELEASE 0

// OWL Version Number (Major, Minor, Release, Build)
// All other version numbers and strings should be defined in terms of this.
// NB! No leading zeroes in the numbers! (leading zero = octal)
//
#define OWL_VERSION(v) v(6,34,3,$WCREV$)

// OWL File Version (major, minor, release, build)
//
#define OWL_FORMAT_VERSION_4WORD(major, minor, release, build) major, minor, release, build
#define OWL_FILEVERSION OWL_VERSION(OWL_FORMAT_VERSION_4WORD)

// OWL Product Version (major, minor, release, build)
//
#define OWL_PRODUCTVERSION OWL_FILEVERSION

// OWL File Version String ("major.minor.release.build")
//
#define OWL_FORMAT_VERSION_STRING(major, minor, release, build) #major "." #minor "." #release "." #build
#define OWL_FILEVERSION_STRING OWL_VERSION(OWL_FORMAT_VERSION_STRING)

// OWL Product Version String ("major.minor" for stable release, "major.minor.release" for prerelease)
//
#define OWL_FORMAT_VERSION_MAJOR_MINOR_STRING(major, minor, release, build) #major "." #minor
#define OWL_FORMAT_VERSION_MAJOR_MINOR_RELEASE_STRING(major, minor, release, build) #major "." #minor "." #release
#if OWL_PRERELEASE
# define OWL_PRODUCTVERSION_STRING OWL_VERSION(OWL_FORMAT_VERSION_MAJOR_MINOR_RELEASE_STRING)
#else
# define OWL_PRODUCTVERSION_STRING OWL_VERSION(OWL_FORMAT_VERSION_MAJOR_MINOR_STRING)
#endif

// 16, 32 and 64-bit internal version numbers
// 16-bit: 0xMmNn, where M = Major / 10, m = Major % 10, N = Minor / 10, n = minor % 10
// 32-bit: 0xMmNnBBBB, where M = Major / 10, m = Major % 10, N= Minor / 10, n = minor % 10, B = Build % 65536
// 64-bit: 0xMMMMNNNNRRRRBBBB, where M = Major, N = Minor, R = Release, B = Build % 65536
// E.g. 0x0620, 0x06200193 and 0x0006001400010193 (6.20.1.403)
//
#define OWL_FORMAT_VERSION_16BIT(major, minor, release, build) (((major / 10) << 12) | ((major % 10) << 8) | ((minor / 10) << 4) | (minor % 10))
#define OWL_FORMAT_VERSION_32BIT(major, minor, release, build) (((OWL_FORMAT_VERSION_16BIT(major, minor, 0, 0)) << 16) | (build % 65536))
#define OWL_FORMAT_VERSION_64BIT(major, minor, release, build) ((uint64(major) << 48) | (uint64(minor) << 32) | (release << 16) | (build % 65536))
#define OWL_VERSION_16BIT OWL_VERSION(OWL_FORMAT_VERSION_16BIT)
#define OWL_VERSION_32BIT OWL_VERSION(OWL_FORMAT_VERSION_32BIT)
#define OWL_VERSION_64BIT OWL_VERSION(OWL_FORMAT_VERSION_64BIT)

// Revision information
//
#define OWL_BUILD_REVISION $WCREV$
#define OWL_BUILD_REVISION_DATE "$WCDATEUTC$"
#define OWL_BUILD_MIXED $WCMIXED?1:0$ // If the build is based on mixed revisions of code then 1, else 0.
#define OWL_BUILD_DIRTY $WCMODS?1:0$ // If the build was using modified source code then 1, else 0.

// Backwards compatibility support
//
#if !defined(OWL_COMPATIBILITY) || OWL_COMPATIBILITY < 632
# define _OWL_VERSION(v) OWL_VERSION(v)
# define OWLVersion OWL_VERSION_16BIT
# define OWLInternalVersion OWL_VERSION_32BIT
# define OWLFileVersion OWL_FILEVERSION
# define OWLProductVersion OWL_PRODUCTVERSION
# define OWLFileVersionString OWL_FILEVERSION_STRING
# define OWLProductVersionString OWL_PRODUCTVERSION_STRING
#endif

#endif  //  OWL_VERSION_H
