//===--- UnknownSyntax.h - Swift Unknown Syntax Interface -------*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2017 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//

#ifndef SWIFT_SYNTAX_UNKNOWNSYNTAX_H
#define SWIFT_SYNTAX_UNKNOWNSYNTAX_H

#include "swift/Syntax/SyntaxData.h"
#include "swift/Syntax/Syntax.h"

#include <vector>

namespace swift {
namespace syntax {

#pragma mark unknown-syntax API

/// A chunk of "unknown" syntax.
///
/// Effectively wraps a tree of RawSyntax.
///
/// This should not be vended by SyntaxFactory.
class UnknownSyntax : public Syntax {
  friend struct SyntaxFactory;
  friend class Syntax;

  virtual void validate() const override;
public:
  UnknownSyntax(const RC<SyntaxData> Root, const SyntaxData *Data)
    : Syntax(Root, Data) {}

  /// Get the number of child nodes in this piece of syntax, not including
  /// tokens.
  size_t getNumChildren() const;

  /// Get the Nth child of this piece of syntax.
  Syntax getChild(const size_t N) const;

  static bool classof(const Syntax *S) {
    return S->isUnknown();
  }
};

} // end namespace syntax
} // end namespace swift

#endif // SWIFT_SYNTAX_UNKNOWNSYNTAX_H
