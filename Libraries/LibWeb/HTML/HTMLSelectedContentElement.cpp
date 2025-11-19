/*
 * Copyright (c) 2025, Feng Yu <f3n67u@outlook.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibWeb/Bindings/HTMLSelectedContentElementPrototype.h>
#include <LibWeb/Bindings/Intrinsics.h>
#include <LibWeb/HTML/HTMLSelectedContentElement.h>

namespace Web::HTML {

GC_DEFINE_ALLOCATOR(HTMLSelectedContentElement);

HTMLSelectedContentElement::HTMLSelectedContentElement(DOM::Document& document, DOM::QualifiedName qualified_name)
    : HTMLElement(document, move(qualified_name))
{
}

HTMLSelectedContentElement::~HTMLSelectedContentElement() = default;

void HTMLSelectedContentElement::initialize(JS::Realm& realm)
{
    WEB_SET_PROTOTYPE_FOR_INTERFACE(HTMLSelectedContentElement);
    Base::initialize(realm);
}

}
