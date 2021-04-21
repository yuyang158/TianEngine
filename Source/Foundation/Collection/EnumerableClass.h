#pragma once
#include <Basic/Types.h>

namespace Foundation {
	template <typename Derived, typename Base = NoBase>
	class Enumerable : public Base
	{
	public:
		Enumerable()
		{
			if (Derived::s_pFirstInstance == nullptr)
				Derived::s_pFirstInstance = this;
			else
				Derived::s_pLastInstance->m_pNextInstance = this;

			Derived::s_pLastInstance = this;
			m_pNextInstance = nullptr;
			++Derived::s_uiInstances;
		}

		virtual ~Enumerable()
		{
			--Derived::s_uiInstances;
			Enumerable* pPrev = nullptr;
			Enumerable* pCur = Derived::s_pFirstInstance;

			while (pCur)
			{
				if (pCur == this)
				{
					if (pPrev == nullptr)
						Derived::s_pFirstInstance = m_pNextInstance;
					else
						pPrev->m_pNextInstance = m_pNextInstance;

					if (Derived::s_pLastInstance == this)
						Derived::s_pLastInstance = pPrev;

					break;
				}

				pPrev = pCur;
				pCur = pCur->m_pNextInstance;
			}
		}

	protected:
		Enumerable* m_pNextInstance;
	};
}


#define TIAN_DECLARE_ENUMERABLE_CLASS(self) TIAN_DECLARE_ENUMERABLE_CLASS_WITH_BASE(self, NoBase)

#define TIAN_DECLARE_ENUMERABLE_CLASS_WITH_BASE(self, base)                      \
private:                                                                       \
  typedef base EnumerableBase;                                               \
  friend class Enumerable<self, base>;                                       \
  static Enumerable<self, base>* s_pFirstInstance;                           \
  static Enumerable<self, base>* s_pLastInstance;                            \
  static uint32 s_uiInstances;                                               \
                                                                               \
public:                                                                        \
  static self* GetFirstInstance() { return (self*)s_pFirstInstance; }          \
  self* GetNextInstance() { return (self*)m_pNextInstance; }                   \
  const self* GetNextInstance() const { return (const self*)m_pNextInstance; } \
                                                                               \
private:

/// \brief Insert this macro in a cpp file and pass the class name of the to-be-enumerable class as the parameter.
///
/// See class ezEnumerable for more details.
#define TIAN_ENUMERABLE_CLASS_IMPLEMENTATION(self)                                \
  Enumerable<self, self::ezEnumerableBase>* self::s_pFirstInstance = nullptr; \
  Enumerable<self, self::ezEnumerableBase>* self::s_pLastInstance = nullptr;  \
  uint32 self::s_uiInstances = 0
