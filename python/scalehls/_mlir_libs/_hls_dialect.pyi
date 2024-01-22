from typing import ClassVar


class PortKind:
    __members__: ClassVar[dict] = ...  # read-only
    __entries: ClassVar[dict] = ...
    input: ClassVar[PortKind] = ...
    output: ClassVar[PortKind] = ...
    param: ClassVar[PortKind] = ...
    def __init__(self, value: int) -> None: ...
    def __eq__(self, other: object) -> bool: ...
    def __hash__(self) -> int: ...
    def __index__(self) -> int: ...
    def __int__(self) -> int: ...
    def __ne__(self, other: object) -> bool: ...
    @property
    def name(self) -> str: ...
    @property
    def value(self) -> int: ...
