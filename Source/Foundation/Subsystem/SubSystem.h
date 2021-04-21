#pragma once

#include <Collection/EnumerableClass.h>

namespace Foundation {
	struct StartupStage {
		enum Enum {
			None = -1,
			BaseSystems, ///< In this stage the absolute base functionality is started. This should only be used by the Foundation library.
			CoreSystems, ///< In this stage the core functionality is being started / shut down
			HighLevelSystems, ///< In this stage the higher level functionality, which depends on a rendering context, is being started / shut down

			ENUM_COUNT
		};
	};

	class SubSystem : public Enumerable<SubSystem> {
		TIAN_DECLARE_ENUMERABLE_CLASS(SubSystem);
		TIAN_DISALLOW_COPY_AND_ASSIGN(SubSystem);

	public:
		SubSystem() {
			m_szPluginName = nullptr;

			for (int32 i = 0; i < StartupStage::ENUM_COUNT; ++i)
				m_bStartupDone[i] = false;
		}

		virtual ~SubSystem() {
			for (int32 i = StartupStage::CoreSystems; i < StartupStage::ENUM_COUNT; ++i) {
				// Can't call GetSubSystemName and GetGroupName, because they are pure virtual and the destructor is called
				// after the derived destructor has already run, thus those virtual functions are potentially not available anymore.
				// This actually gives a linker error already.
				// EZ_ASSERT_DEV(!m_bStartupDone[i], "This SubSystem is not entirely shut down. Phase {0} is still active.", i);
			}
		}

		/// \brief Returns the name of the subsystem. Must be overridden.
		virtual const char* GetSubSystemName() const = 0;

		/// \brief Returns the name of the group to which this subsystem belongs. Must be overridden.
		virtual const char* GetGroupName() const = 0;

		/// \brief Returns a series of strings with the names of the subsystem, which this subsystem depends on. nullptr indicates the last entry.
		/// Must be overridden.
		virtual const char* GetDependency(int32 iDep) { return nullptr; }

		/// \brief Returns the plugin name to which this subsystem belongs.
		const char* GetPluginName() const { return m_szPluginName; }

		/// \brief Returns whether the given startup stage has been done on this subsystem.
		bool IsStartupPhaseDone(StartupStage::Enum Stage) const { return m_bStartupDone[Stage]; }

	private:
		// only the startup system may access the following functionality
		friend class Startup;

		/// \brief This will be called to initialize the subsystems base components. Can be overridden to handle this event.
		virtual void OnBaseSystemsStartup() {}

		/// \brief This will be called to initialize the subsystems core components. Can be overridden to handle this event.
		virtual void OnCoreSystemsStartup() {}

		/// \brief This will be called to shut down the subsystems core components. Can be overridden to handle this event.
		virtual void OnCoreSystemsShutdown() {}

		/// \brief This will be called to initialize the subsystems engine / rendering components. Can be overridden to handle this event.
		virtual void OnHighLevelSystemsStartup() {}

		/// \brief This will be called to shut down the subsystems engine / rendering components. Can be overridden to handle this event.
		virtual void OnHighLevelSystemsShutdown() {}

		/// Set by ezStartup to store to which plugin this subsystem belongs.
		const char* m_szPluginName;

		/// Stores which startup phase has been done already.
		bool m_bStartupDone[StartupStage::ENUM_COUNT];
	};
}


#include <Subsystem//StaticSubSystem.h>
